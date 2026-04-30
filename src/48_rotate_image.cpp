#include "48_rotate_image.h"
#include "class_version.h"

#include <algorithm>

namespace _48 {

    /*
    * This results in a 90-degree clockwise in-place rotation.
    * 
    * 1) Transpose the matrix along its main diagonal.
    * 2) Reverse each row.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(1) - in-place rotation, no extra space needed.
    */
    template<>
    void Solution<ver1>::rotate(std::vector<std::vector<int>>& matrix) {
        const int n = static_cast<int>(matrix.size());

        for (const auto& row : matrix) {
            // Algorithm is valid only for an n x n matrix.
            if (static_cast<int>(row.size()) != n) {
                return;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    /*
    * Rotate by layers (rings) with four direct assignments per step.
    * This version does not use std::swap or std::reverse.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    void Solution<ver2>::rotate(std::vector<std::vector<int>>& matrix) {
        const int n = static_cast<int>(matrix.size());

        for (const auto& row : matrix) {
            if (static_cast<int>(row.size()) != n) {
                return;
            }
        }

        for (int layer = 0; layer < n / 2; ++layer) {
            const int first = layer;
            const int last = n - 1 - layer;

            for (int i = first; i < last; ++i) {
                const int offset = i - first;
                const int top = matrix[first][i];

                matrix[first][i] = matrix[last - offset][first];
                matrix[last - offset][first] = matrix[last][last - offset];
                matrix[last][last - offset] = matrix[i][last];
                matrix[i][last] = top;
            }
        }
    }

}