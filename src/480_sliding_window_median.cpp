#include "480_sliding_window_median.h"

#include <algorithm>
#include <set>

namespace _480 {

    /**
    * std::sort k elements approach
    *
    * Time complexity:
    * O(n × k log k), where n=nums.size()
    *
    * Space complexity:
        O(K)
    */
    template<>
    std::vector<double> Solution<_480_v1>::medianSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<double> result;
        if (nums.empty() || nums.size() < k) {
            return result;
        }

        bool isOdd = (k % 2 != 0);
        size_t mid_offset = k / 2;
        std::vector<int> temp;

        for (size_t i = 0; (i + k) <= nums.size(); ++i) {
            temp.assign(nums.begin() + i, nums.begin() + (i + k));
            std::sort(temp.begin(), temp.end());
            if (isOdd) {
                result.push_back(static_cast<double>(temp[mid_offset]));
            }
            else {
                result.push_back((static_cast<double>(temp[mid_offset]) + temp[mid_offset - 1]) / 2.0);
            }
        }

        return result;
    }

    /**
    * std::nth_element approach
    *
    * Time complexity:
    * O(n × k), where n=nums.size()
    *
    * Space complexity:
        O(K)
    */
    template<>
    std::vector<double> Solution<_480_v2>::medianSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<double> result;
        if (nums.empty() || nums.size() < k) {
            return result;
        }

        bool isOdd = (k % 2 != 0);
        size_t mid_offset = k / 2;
        std::vector<int> temp(k);

        for (size_t i = 0; (i + k) <= nums.size(); ++i) {
            std::copy(nums.begin() + i, nums.begin() + (i + k), temp.begin());

            if (isOdd) { // if arr = [2,3,4], the median is 3
                std::nth_element(temp.begin(), temp.begin() + mid_offset, temp.end());
                result.push_back(static_cast<double>(temp[mid_offset]));
            }
            else { // if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5
                // std::nth_element does not guarantee sorting of elements to the left of the nth element.
                std::nth_element(temp.begin(), temp.begin() + mid_offset, temp.end());

                double right = temp[mid_offset];
                double left = *std::max_element(temp.begin(), temp.begin() + mid_offset);
                result.push_back((left + right) / 2.0);
            }
        }

        return result;
    }

    /**
    * multiset approach.
    * 
    * The solution effectively finds the median of every sliding window of size k in linearithmic time, 
    * leveraging the power of balanced tree-like structures (std::multiset). 
    * Its efficiency makes it suitable large datasets.
    * 
    * Time complexity:
    * O(n × log k) - best asymptotic behavior for big data
    *
    * Space complexity:
        O(K)
    */
    template<>
    std::vector<double> Solution<_480_v3>::medianSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<double> result;
        if (nums.empty() || nums.size() < k) {
            return result;
        }

        std::multiset<int> right, left;

        auto getMedian = [&]() -> double {
            if (k % 2 != 0) {
                return static_cast<double>(*right.begin());
            }
            return (static_cast<double>(*left.rbegin()) + *right.begin()) / 2.0;
            };

        auto balance = [&]() {
            while (left.size() > right.size()) {
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }
            while (right.size() > left.size() + (k % 2)) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            };

        // add k elements into containers
        for (size_t i = 0; i < k; ++i) {
            left.insert(nums[i]);
        }
        balance();

        result.push_back(getMedian());

        for (size_t i = k; i < nums.size(); ++i) {
            // remove old element
            if (left.count(nums[i - k])) {
                left.erase(left.find(nums[i - k]));
            }
            else {
                right.erase(right.find(nums[i - k]));
            }

            // add new element
            if (right.empty() || nums[i] <= *right.begin()) {
                left.insert(nums[i]);
            }
            else {
                right.insert(nums[i]);
            }

            balance();

            result.push_back(getMedian());

        }
        return result;
    }
}