#include "373_find_k_pairs_with_smallest_sums.h"

#include <queue>
#include <tuple>

namespace _373 {

    /**
    This implementation uses a greedy approach combined with a priority queue to efficiently track the smallest sums.
    It optimizes by skipping calculations when it knows future pairs cannot give better solutions, making it suitable for large inputs.

    Time complexity:
        O(n*mlogk), k is the number of pairs we are looking for

    Space complexity:
        O(K)
    */
    template<>
    std::vector<std::vector<int>> Solution<v1>::kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) {
            return result;
        }

        std::priority_queue<std::pair<int, std::pair<int, int>>>pq;
        for (int i = 0; i < nums1.size(); ++i) {
            if (pq.size() == k && nums1[i] + nums2[0] >= pq.top().first) {
                break; // next pair will be bigger
            }

            for (int j = 0; j < nums2.size(); ++j) {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k) {
                    pq.push({ sum, { nums1[i], nums2[j] } });
                }
                else if (sum < pq.top().first) {
                    pq.pop();
                    pq.push({ sum, { nums1[i], nums2[j] } });
                }
                else {
                    break;
                }
            }
        }

        while (!pq.empty()) {
            result.push_back({ pq.top().second.first, pq.top().second.second });
            pq.pop();
        }

        return { result.crbegin(), result.crend() };
    }

    /**
    * std::tuple<int, int, int>
    *
    Time complexity:
        O(klogk)), k is the number of pairs we are looking for

    Space complexity:
        O(min(k))
    */
    template<>
    std::vector<std::vector<int>> Solution<v2>::kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) {
            return result;
        }

        using T = std::tuple<int, int, int>;
        std::priority_queue<T, std::vector<T>, std::greater<T>> pq;

        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({ nums1[i] + nums2[0], i, 0 });
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            result.push_back({ nums1[i], nums2[j] });

            if (j + 1 < nums2.size()) {
                pq.push({ nums1[i] + nums2[j + 1], i, j + 1 });
            }
        }

        return result;
    }

    /**
    * std::pair<int, std::pair<int, int>>
    *
    Time complexity:
        O(klog min(k,n)), k is the number of pairs we are looking for; n - nums1 size

    Space complexity:
        O(min(k,n))
    */
    template<>
    std::vector<std::vector<int>> Solution<v3>::kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) {
            return result;
        }

        auto cmp = [](const auto& a, const auto& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            if (a.second.first != b.second.first) {
                return a.second.first > b.second.first;
            }
            return a.second.second > b.second.second;
            };

        std::priority_queue<std::pair<int, std::pair<int, int>>,
            std::vector<std::pair<int, std::pair<int, int>>>,
            decltype(cmp)> pq(cmp);

        for (int i = 0; i < std::min(static_cast<int>(nums1.size()), k); i++) {
            pq.push({ nums1[i] + nums2[0], { i, 0 } });
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, indices] = pq.top();
            pq.pop();

            int i = indices.first, j = indices.second;
            result.push_back({ nums1[i], nums2[j] });

            if (j + 1 < nums2.size()) {
                pq.push({ nums1[i] + nums2[j + 1], { i, j + 1 } });
            }
        }

        return result;
    }

}