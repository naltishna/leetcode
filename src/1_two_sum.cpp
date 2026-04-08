#include "1_two_sum.h"
#include "class_version.h"

#include <unordered_map>

#include <algorithm>

namespace _1 {

    /*
    * Time complexity:
    * O(N^2)
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    std::vector<int> Solution<v1>::twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        for (int index1 = 0; index1 < n; ++index1) {
            for (int index2 = index1 + 1; index2 < n; ++index2) {
                int sum = nums[index1] + nums[index2];
                if (sum == target) {
                    return { index1, index2 };
                }
            }
        }

        return {};
    }

    /*
    * One-pass Hash Table approach.
    * 
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    template<>
    std::vector<int> Solution<v2>::twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (num_map.find(complement) != num_map.end()) {
                return { num_map[complement], i };
            }

            num_map[nums[i]] = i;
        }

        return {};
    }

}