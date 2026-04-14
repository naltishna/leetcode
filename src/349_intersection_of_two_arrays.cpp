#include "349_intersection_of_two_arrays.h"

#include <unordered_set>

namespace _349 {

    /*
    * Convert both arrays into unordered_set to eliminate duplicates.
    * Iterate over the smaller set, check membership in the other via O(1) lookup.
    * If found — add to result.
    *
    * Time complexity:
    * O(n+m)
    * 
    * Space complexity:
    * O(n+m)
    */
    std::vector<int> Solution::intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        std::unordered_set<int> nums2_set(nums2.begin(), nums2.end());
        std::vector<int> res;

        for (auto n : nums1_set) {
            if (nums2_set.find(n) != nums2_set.end()) {
                res.push_back(n);
            }
        }

        return res;
    }

}