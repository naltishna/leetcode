#include "73_set_matrix_zeroes.h"

namespace _73 {

    /*
    * First pass — scans the entire matrix, records which rows and columns contain a zero into two vectors.
    * Second pass — zeros out any cell whose row or column was marked.
    *
    * Time complexity:
    * O(m × n) — two full passes over the matrix
    *
    * Space complexity:
    * O(m + n) — two marker vectors
    */
    void Solution::setZeroes(std::vector<std::vector<int>>& matrix) {
        const int rows = static_cast<int>(matrix.size());
        if (rows == 0) {
            return;
        }

        const int cols = static_cast<int>(matrix[0].size());
        if (cols == 0) {
            return;
        }

        std::vector<char> rowsToZero(rows, 0);
        std::vector<char> colsToZero(cols, 0);

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == 0) {
                    rowsToZero[row] = 1;
                    colsToZero[col] = 1;
                }
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (rowsToZero[row] || colsToZero[col]) {
                    matrix[row][col] = 0;
                }
            }
        }
    }

}