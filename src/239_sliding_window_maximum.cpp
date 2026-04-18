#include "239_sliding_window_maximum.h"
#include "class_version.h"

#include <algorithm>
#include <deque>

namespace _239 {

    /*
    * Time complexity:
    * 𝑂(𝑛𝑘)
    * 
    * Space complexity:
    * 𝑂(𝑛𝑘)
    */
    template<>
    std::vector<int> Solution<ver1>::maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        if (nums.empty() || nums.size() < k) return res;

        std::vector<int> temp(k);
        for (size_t i = 0; (i + k) <= nums.size(); ++i) {
            std::copy(nums.begin() + i, nums.begin() + (i + k), temp.begin());
            res.push_back(*std::max_element(temp.begin(), temp.end()));
        }

        return res;
    }

    /*
    * Time complexity:
    * 𝑂(𝑛)
    *
    * Space complexity:
    * 𝑂(𝑛)
    */
    template<>
    std::vector<int> Solution<ver2>::maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        if (nums.empty() || nums.size() < k) return res;

        std::deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
}