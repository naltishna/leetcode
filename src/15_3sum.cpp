#include "15_3sum.h"
#include "class_version.h"

#include <algorithm>

namespace _15 {

    /*
    * Time complexity:
    * O(N^3)
    *
    * Space complexity:
    * O(N^2)
    */

    template<>
    std::vector<std::vector<int>> Solution<v1>::threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        size_t end = nums.size();
        if (end < 3) return triplets;

        std::sort(nums.begin(), nums.end());

        for (size_t start = 0; start < end - 2; ++start) {
            if (start > 0 && nums[start] == nums[start - 1]) continue;

            for (size_t next = start + 1; next < end - 1; ++next) {
                if (next > start + 1 && nums[next] == nums[next - 1]) continue;

                size_t right = next + 1;
                while (right < end) {
                    long long sum = static_cast<long long>(nums[start]) + nums[next] + nums[right];
                    if (0 == sum) {
                        triplets.push_back({ nums[start], nums[next], nums[right] });
                    }
                    right++;
                }
            }
        }

        return triplets;
    }

    /*
    * Two-pointer strategy.
    * Sort array then use two pointers to find triplets summing to zero while skipping duplicates.
    * 
    * Time complexity:
    * O(N^2)
    * 
    * Space complexity:
    * O(logN)
    */
    template<>
    std::vector<std::vector<int>> Solution<v2>::threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        size_t end = nums.size();
        if (end < 3) return triplets;

        std::sort(nums.begin(), nums.end());

        for (size_t start = 0; start < end - 2; ++start) {
            if (start > 0 && nums[start] == nums[start - 1]) continue;

            size_t left = start + 1;
            size_t right = end - 1;

            while (left < right) {
                long long sum = static_cast<long long>(nums[start]) + nums[left] + nums[right];

                if (sum == 0) {
                    triplets.push_back({ nums[start], nums[left], nums[right] });

                    // skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++; // sum is too small
                }
                else {
                    right--; // sum is too big
                }
            }
        }

        return triplets;
    }

}