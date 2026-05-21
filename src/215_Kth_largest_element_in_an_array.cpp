#include "215_Kth_largest_element_in_an_array.h"
#include "class_version.h"

#include <algorithm>
#include <queue>
#include <vector>

namespace _215 {

    /*
    * Min-Heap of size k approach.
    *
    * When size exceeds k, pops the smallest - so the heap always holds the k largest, and top() is the k-th largest.
    *
    * Time complexity:
    * O(n log k) - n insertions, each heap operation costs O(log k)
    *
    * Space complexity:
    * O(k) - heap never exceeds k elements
    */
    template <>
    int Solution<ver1>::findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (int n : nums) {
            pq.push(n);
            if (static_cast<int>(pq.size()) > k) {
                pq.pop();
            }
        }

        return pq.top();
    }

    /*
    * nth_element partitions so the element at index (n - k) is the kth largest.
    * Mutates nums.
    *
    * Time complexity:
    * O(n) average, O(n^2) worst case
    *
    * Space complexity:
    * O(1)
    */
    template <>
    int Solution<ver2>::findKthLargest(std::vector<int>& nums, int k) {
        const int idx = static_cast<int>(nums.size()) - k;

        std::nth_element(nums.begin(), nums.begin() + idx, nums.end());

        return nums[idx];
    }

}
