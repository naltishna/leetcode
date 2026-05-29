#include "52_n_queens_II.h"
#include "class_version.h"

#include <functional>
#include <unordered_set>
#include <vector>

namespace _52 {

    /*
    * Approach: Backtracking row by row.
    *
    * Places one queen per row and tracks occupied columns and both diagonal directions.
    *
    * Time complexity:
    * O(N!) - N choices for row 1, N-1 for row 2, etc.
    *
    * Space complexity:
    * O(N) - recursion depth + hash sets hold at most N entries each
    */
    template<>
    int Solution<ver1>::totalNQueens(int n) {
        int count = 0;
        std::unordered_set<int> cols;
        std::unordered_set<int> diag1;
        std::unordered_set<int> diag2;

        std::function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                ++count;
                return;
            }

            for (int col = 0; col < n; ++col) {
                const int d1 = row - col;
                const int d2 = row + col;

                if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) {
                    continue;
                }

                cols.insert(col);
                diag1.insert(d1);
                diag2.insert(d2);
                backtrack(row + 1);
                cols.erase(col);
                diag1.erase(d1);
                diag2.erase(d2);
            }
            };

        backtrack(0);

        return count;
    }

    /*
    * Approach: Iterative backtracking with stack.
    *
    * Each stack frame stores the current row, the next column to try, and occupied
    * columns/diagonals. When a valid queen placement is found, a new frame is pushed.
    *
    * Time complexity:
    * O(n!) in the worst case
    *
    * Space complexity:
    * O(n) - stack depth and tracking sets
    */
    template<>
    int Solution<ver2>::totalNQueens(int n) {
        int count = 0;

        struct Frame {
            int row;
            int col;
            std::unordered_set<int> cols;
            std::unordered_set<int> diag1;
            std::unordered_set<int> diag2;
        };

        std::vector<Frame> stack;
        stack.push_back({ 0, 0, {}, {}, {} });

        while (!stack.empty()) {
            Frame& frame = stack.back();

            if (frame.row == n) {
                ++count;
                stack.pop_back();
                continue;
            }

            if (frame.col == n) {
                stack.pop_back();
                continue;
            }

            const int col = frame.col++;
            const int d1 = frame.row - col;
            const int d2 = frame.row + col;

            if (frame.cols.count(col) || frame.diag1.count(d1) || frame.diag2.count(d2)) {
                continue;
            }

            Frame next = frame;
            next.row = frame.row + 1;
            next.col = 0;
            next.cols.insert(col);
            next.diag1.insert(d1);
            next.diag2.insert(d2);
            stack.push_back(std::move(next));
        }

        return count;
    }

}
