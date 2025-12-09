#include "26_remove_duplicates_from_sorted_array.h"

#include <algorithm>

namespace _26 {

    /*
    * The algorithm moves unique elements forward, leaving duplicates at the end of the array, preserves the relative order of the elements.
    * An iterator points to the first element after the unique values.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<_26_v1>::removeDuplicates(std::vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        return (it - nums.begin());
    }

    /*
    * erase() requires moving all elements to the right of the deleted element, which is an expensive O(n) operation.
    * Thus, in the worst case, each element must be moved multiple times, resulting in a quadratic time complexity of O(n²).
    *
    * - Time complexity:
    * O(n²)
    *
    * - Space complexity:
    * O(1)
    */
    template<>
    int Solution<_26_v2>::removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        for (int i = 0, j = 1; j < nums.size();) {
            if (nums[i] == nums[j]) {
                nums.erase(nums.begin() + j);
            }
            else {
                ++i;
                ++j;
            }
        }

        return nums.size();
    }

}