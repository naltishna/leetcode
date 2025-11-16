#include "136_single_number.h"

#include <algorithm>

namespace _136 {

#ifdef O_N_136
    //O(N)
    int Solution::singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
#else
    //O(NLogN)
    int Solution::singleNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int target = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (target != nums[i]) {
                break;
            }
            if (i + 1 < nums.size()) {
                target = nums[++i];
            }
        }
        return target;
    }
#endif
}