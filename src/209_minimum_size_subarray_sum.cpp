#include "209_minimum_size_subarray_sum.h"
#include "class_version.h"

#include <numeric>

namespace _209 {

    /*
    * The Brute Force approach.
    *
    * Time complexity:
    * O(N^2)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver1>::minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int minLen = std::numeric_limits<int>::max();

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];

                if (sum >= target) {
                    int curLen = j - i + 1; // convert from indices to segment length
                    minLen = std::min(minLen, curLen);
                    break;
                }
            }
        }

        return (minLen == std::numeric_limits<int>::max()) ? 0 : minLen;
    }

    /*
    * Move the right pointer to add elements to the sum.
    * Once sum >= target, move the left pointer to find the smallest possible window that still satisfies the condition.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::minSubArrayLen(int target, std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int minLen = std::numeric_limits<int>::max();
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLen = std::min(minLen, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }

        return (minLen == std::numeric_limits<int>::max()) ? 0 : minLen;
    }

}