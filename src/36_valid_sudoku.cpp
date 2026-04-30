#include "36_valid_sudoku.h"
#include "class_version.h"

#include <array>
#include <unordered_set>
#include <cctype>

namespace _36 {

    /*
    * For each digit d, sets bit 1 << d in a mask. If that bit is already set -> duplicate found -> invalid.
    *
    * Three separate passes validate: 3×3 boxes — iterates over 9 sub-grids;
    * Rows + Columns — checked simultaneously in a single pass (using board[i][j] and board[j][i]).
    *
    * Time complexity:
    * O(1) — always exactly 81 cells processed (fixed 9×9 board)
    *
    * Space complexity:
    * O(1) — only a few integer masks, no extra data structures
    */
    template<>
    bool Solution<ver1>::isValidSudoku(std::vector<std::vector<char>>& board) {
        int n = board.size();

        for (int row = 0; row < n; row += 3) {
            for (int col = 0; col < n; col += 3) {
                int boxMask = 0;

                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char val = board[row + i][col + j];
                        if (val != '.') {
                            if (val < '1' || val > '9') {
                                return false;
                            }

                            int num = val - '0';
                            int bit = 1 << num;
                            if (boxMask & bit) return false;
                            boxMask |= bit;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            int rowMask = 0;
            int colMask = 0;

            for (int j = 0; j < n; ++j) {
                char val = board[i][j];
                if (val != '.') {
                    if (val < '1' || val > '9') {
                        return false;
                    }

                    int num = val - '0';
                    int bit = 1 << num;
                    if (rowMask & bit) return false;
                    rowMask |= bit;
                }

                val = board[j][i];
                if (val != '.') {
                    if (val < '1' || val > '9') {
                        return false;
                    }

                    int num = val - '0';
                    int bit = 1 << num;
                    if (colMask & bit) return false;
                    colMask |= bit;
                }
            }
        }

        return true;
    }

    /*
    * Time complexity:
    * O(1)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    bool Solution<ver2>::isValidSudoku(std::vector<std::vector<char>>& board) {
        if (board.size() != 9) {
            return false;
        }

        std::array<int, 9> rowMask{};
        std::array<int, 9> colMask{};
        std::array<int, 9> boxMask{};

        for (int row = 0; row < 9; ++row) {
            if (board[row].size() != 9) {
                return false;
            }

            for (int col = 0; col < 9; ++col) {
                const char c = board[row][col];
                if (c == '.') {
                    continue;
                }

                if (c < '1' || c > '9') {
                    return false;
                }

                const int value = c - '1'; // Convert chars '1'..'9' to indexes 0..8.
                const int mask = 1 << value; // Create mask for the current digit.
                const int box = (row / 3) * 3 + (col / 3); // 3x3 sub-box coordinates.

                if ((rowMask[row] & mask) || (colMask[col] & mask) || (boxMask[box] & mask)) {
                    return false;
                }

                rowMask[row] |= mask;
                colMask[col] |= mask;
                boxMask[box] |= mask;
            }
        }

        return true;
    }

}