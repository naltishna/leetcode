#include "88_merge_sorted_array.h"

#include <algorithm>

namespace _88 {

    /*
    * The algorithm iterates through two sorted vectors, nums1 and nums2, starting from the end of each array, and selects the larger value, placing it at the end of nums1.
    * This allows for the efficient merging of two sorted arrays directly within the first array, without requiring additional memory.
    * 
    * Time complexity:
    * O(M+N)
    * 
    * Space complexity:
    * O(1)
    */
    void Solution::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }
    }

}