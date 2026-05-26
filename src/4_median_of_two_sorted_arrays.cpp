#include "4_median_of_two_sorted_arrays.h"
#include "class_version.h"

#include <algorithm>
#include <climits>

namespace _4 {

    /*
    * Approach: Binary search on partition.
    *
    * Binary searches the cut position in the smaller array so that the left
    * halves of both arrays contain exactly half of all elements.
    *
    * Time complexity:
    * O(log(m + n))
    *
    * Space complexity:
    * O(1)
    */
    template<>
    double Solution<ver1>::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return Solution<ver1>::findMedianSortedArrays(nums2, nums1);
        }

        const int m = static_cast<int>(nums1.size());
        const int n = static_cast<int>(nums2.size());
        int left = 0;
        int right = m;

        while (left <= right) {
            const int partition1 = left + (right - left) / 2;
            const int partition2 = (m + n + 1) / 2 - partition1;

            const int leftMax1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            const int rightMin1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            const int leftMax2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            const int rightMin2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
                if ((m + n) % 2 != 0) {
                    return static_cast<double>(std::max(leftMax1, leftMax2));
                }

                return (static_cast<double>(std::max(leftMax1, leftMax2)) +
                    static_cast<double>(std::min(rightMin1, rightMin2))) / 2.0;
            }

            if (leftMax1 > rightMin2) {
                right = partition1 - 1;
            }
            else {
                left = partition1 + 1;
            }
        }

        return 0.0;
    }

    /*
    * Approach: Two-pointer merge.
    *
    * Walks both arrays like merge sort until the median position(s) are reached.
    *
    * Time complexity:
    * O(m + n)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    double Solution<ver2>::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        const int m = static_cast<int>(nums1.size());
        const int n = static_cast<int>(nums2.size());
        const int total = m + n;
        const int mid = total / 2;

        int i = 0;
        int j = 0;
        int current = 0;
        int prev = 0;

        for (int count = 0; count <= mid; ++count) {
            prev = current;

            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                current = nums1[i++];
            }
            else {
                current = nums2[j++];
            }
        }

        if (total % 2 != 0) {
            return static_cast<double>(current);
        }

        return (static_cast<double>(prev) + current) / 2.0;
    }

    /*
    * For each element in nums2, binary search (lower_bound) for its position in nums1 and
    * insert it - keeping nums1 sorted throughout. Then compute median directly by index.
    *
    * Time complexity:
    * O(n·m) — n insertions, each shifting up to m elements
    *
    * Space complexity:
    * O(1) extra — merges in-place into nums1 (reserve avoids realloc)
    */
    template<>
    double Solution<ver3>::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) {
            return 0.0;
        }

        nums1.reserve(nums1.size() + nums2.size());

        for (int n : nums2) {
            std::vector<int>::iterator it = std::lower_bound(nums1.begin(), nums1.end(), n);
            nums1.insert(it, n);
        }

        const int arraySize = static_cast<int>(nums1.size());
        const int offset = arraySize / 2;

        return (arraySize % 2 != 0)
            ? static_cast<double>(nums1[offset])
            : static_cast<double>(nums1[offset - 1] + nums1[offset]) / 2.0;
    }

}
