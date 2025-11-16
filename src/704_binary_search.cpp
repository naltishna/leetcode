#include "704_binary_search.h"

namespace _704_recursion {

    int Solution::search(const std::vector<int>& nums, int target) {
        return recursiveSearch(nums, target, 0, nums.size() - 1);
    }

    int Solution::recursiveSearch(const std::vector<int>& nums, int target, int lowInd, int highInd) {
        if (lowInd > highInd) {
            return -1;
        }

        int mid = lowInd + (highInd - lowInd) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (target > nums[mid]) {
            return recursiveSearch(nums, target, mid + 1, highInd);
        }
        else {
            return recursiveSearch(nums, target, lowInd, mid - 1);
        }
    }

}

namespace _704_STL {

    int Solution::search(const std::vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target) return it - nums.begin();
        return -1;
    }

}

namespace _704_binary_search {

    // const added to make possible using of {} in my_assert(-1 == s.search({}, 5));
    int Solution::search(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

}

namespace _704_linear_search {

    int Solution::search(const std::vector<int>& nums, int target) {
        int idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                idx = i;
                break;
            }
        }
        return idx;
    }

}