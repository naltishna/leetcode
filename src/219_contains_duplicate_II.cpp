#include "219_contains_duplicate_II.h"

#include <unordered_map>

namespace _219 {

    /*
    * Track the last seen index of each number in a hash map.
    * For every element, check if the same value appeared within the last k positions — if so, return true.
    * Always update the map with the current index to keep it fresh.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    bool Solution::containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> lastPosition;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = lastPosition.find(nums[i]);

            if (it != lastPosition.end() && i - it->second <= k) {
                return true;
            }

            lastPosition[nums[i]] = i;
        }

        return false;
    }

}