#include "120_triangle.h"

namespace _120 {

    /*
    * The method of dynamic programming is used, where the task is solved step by step.
    * In this code, we process each row of the triangle from bottom up, beginning with the second-to-last row (thus using the index "-2").
    * For every element, we calculate the minimal sum of paths by adding it to the minimum value among two possible options from the next row below.
    * This way, we form optimal sums for all upper rows until reaching the top of the triangle, which contains the final minimal total sum.
    * 
    * Complexity
    * 
    * Time complexity:
    * O(N^2)
    * 
    * Space complexity:
    * O(1)
    */
    int Solution::minimumTotal(std::vector<std::vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }

        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }

}