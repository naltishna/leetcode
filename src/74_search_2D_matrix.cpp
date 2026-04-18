#include "74_search_2D_matrix.h"
#include "class_version.h"

namespace _74 {

    static int findInRow(std::vector<int>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid] == target) {
                return mid;
            }
            else if (matrix[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }

    /*
    * Current complexity:
    * O(M+logN)
    */
    template<>
    bool Solution<ver1>::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int size = matrix.size();
        int row = 0;

        while (row < size) {
            if (target > matrix[row][matrix[row].size() - 1]) {
                ++row;
            }
            else {
                return findInRow(matrix[row], target) != -1;
            }
        }

        return false;
    }

    /*
    * Binary Search.
    * 
    * To achieve O(log(M*N)) complexity,need to treat the 2D matrix as a single, sorted 1D array. 
    * By using the formula index/cols for the row and index%cols for the column, to perform a single binary search across the entire range.
    * 
    * Time complexity:
    * O(log(M*N))
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    bool Solution<ver2>::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = (rows * cols) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Map 1D index back to 2D coordinates
            int mid_val = matrix[mid / cols][mid % cols];

            if (mid_val == target) {
                return true;
            }
            else if (mid_val < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }

}