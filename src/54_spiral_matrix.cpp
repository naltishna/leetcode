#include "54_spiral_matrix.h"

namespace _54 {

    /*
    * Tracks four borders (top, bottom, left, right) that collapse inward after each side is traversed.
    * Each iteration of the while loop peels one full layer:
    * Left to right along to, then ++top;
    * Top to bottom along right, then right--;
    * Right to left along bottom (only if row still exists), then bottom--;
    * Bottom to top along left (only if column still exists), then left--
    * 
    * Guards on steps 3 & 4 prevent double-counting when the remaining region is a single row or column.
    * 
    * Time complexity:
    * O(m*n) — every cell visited exactly once
    *
    * Space complexity:
    * - O(m*n) total if we count the returned vector `res` (one int per matrix cell).
    * - O(1) auxiliary / extra beyond the output: only a few index variables (top, bottom,
    *   left, right); their count does not grow with m or n.
    */
    std::vector<int> Solution::spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;

        const int rows = static_cast<int>(matrix.size());
        if (rows == 0) {
            return res;
        }

        const int cols = static_cast<int>(matrix[0].size());
        if (cols == 0) {
            return res;
        }

        res.reserve(static_cast<size_t>(rows) * static_cast<size_t>(cols));

        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            ++top;

            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            --right;

            // Move left along the bottom line (if the line remains).
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    res.push_back(matrix[bottom][i]);
                --bottom;
            }

            // Move up the left column (if there is a column left).
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    res.push_back(matrix[i][left]);
                ++left;
            }
        }

        return res;
    }

}