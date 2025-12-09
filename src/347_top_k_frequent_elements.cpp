#include "347_top_k_frequent_elements.h"

#include <algorithm>
#include <unordered_map>

namespace _347 {

    /*
    * Solid and common approach to solve the problem.
    *
    * Complexity
    * Time complexity:
    * O(N + Ulog(U)), where N is the length of the input array, and U is the number of unique elements.
    *
    * Space complexity:
    * O(U + K)
    */
    std::vector<int> Solution::topKFrequent(std::vector<int>& nums, int k) {
        if (nums.empty() || k == 0) {
            return {};
        }

        std::unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }

        std::vector<std::pair<int, int>> all_pair(freq.begin(), freq.end());
        std::sort(all_pair.begin(),
            all_pair.end(), [](const auto& a, const auto& b) {
                return a.second > b.second;
            });

        std::vector<int> result;
        result.reserve(k);
        for (size_t i = 0; i < std::min(k, static_cast<int>(all_pair.size())); ++i) {
            result.push_back(all_pair[i].first);
        }

        return result;
    }

}