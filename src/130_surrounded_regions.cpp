#include "130_surrounded_regions.h"

#include <functional>

namespace _130 {

    /*
    * Approach: DFS (Depth-First Search) from border cells.
    *
    * Instead of finding surrounded regions directly, marks all Os connected to the border
    * as safe (#) via DFS. Then flips remaining Os (surrounded) to X, and restores # back to O.
    *
    * Time complexity:
    * O(m * n) - m is the number of rows, n is the number of columns
    *
    * Space complexity:
    * O(m * n) - recursion depth in the worst case
    */
    void Solution::solve(std::vector<std::vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        std::function<void(int, int)> dfs = [&](int row, int col) {
            if (row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] != 'O') {
                return;
            }

            board[row][col] = '#';

            dfs(row + 1, col); // Down
            dfs(row - 1, col); // Up
            dfs(row, col + 1); // Right
            dfs(row, col - 1); // Left
            };

        // process the left and right borders
        for (int row = 0; row < rows; ++row) {
            if (board[row][0] == 'O') {
                dfs(row, 0);
            }

            if (board[row][cols - 1] == 'O') {
                dfs(row, cols - 1);
            }
        }

        // process the top and bottom borders
        for (int col = 0; col < cols; ++col) {
            if (board[0][col] == 'O') {
                dfs(0, col);
            }

            if (board[rows - 1][col] == 'O') {
                dfs(rows - 1, col);
            }
        }

        // restore the cells
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
                else if (board[row][col] == '#') {
                    board[row][col] = 'O';
                }
            }
        }
    }

}
