#include "300_longest_increasing_subsequence.h"

#include "class_version.h"

#include <algorithm>

namespace _300 {

    /*
    * Classic DP: dp[i] = length of LIS ending at index i.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(n)
    */
    int Solution<ver1>::lengthOfLIS(std::vector<int>& nums) {
        const int size = static_cast<int>(nums.size());
        if (size == 0) {
            return 0;
        }

        std::vector<int> dp(size, 1);

        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }

    /*
    * This method maintains a list of the smallest possible elements for all increasing subsequences found so far.
    * It uses binary search to quickly choose whether to extend the longest subsequence or optimize an existing one.
    * For each num: binary search for first tail >= num - replace it, or append if none found.
    *
    * Time complexity:
    * O(n log n)
    *
    * Space complexity:
    * O(n)
    */
    int Solution<ver2>::lengthOfLIS(std::vector<int>& nums) {
        const int size = static_cast<int>(nums.size());
        if (size == 0) {
            return 0;
        }

        std::vector<int> tails;
        tails.reserve(size);

        for (int num : nums) {
            const auto it = std::lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            }
            else {
                *it = num;
            }
        }

        return static_cast<int>(tails.size());
    }

}