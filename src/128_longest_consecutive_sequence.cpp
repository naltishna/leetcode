#include "128_longest_consecutive_sequence.h"

#include <unordered_set>

namespace _128 {

    /*
    * Load all numbers into a hash set. For each number, skip it if value - 1 exists (it's not a sequence start).
    * Only from true starts, walk forward counting consecutive numbers. Track the maximum length found.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    int Solution::longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> values(nums.begin(), nums.end());

        int longestLength = 0;
        for (int value : values) {
            if (values.count(value - 1) != 0) {
                continue;
            }

            int length = 1;
            while (values.count(value + length) != 0) {
                ++length;
            }

            longestLength = std::max(longestLength, length);
        }

        return longestLength;
    }

}
