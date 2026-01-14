#include "169_majority_element.h"
#include "class_version.h"

#include <queue>
#include <unordered_map>

namespace _169 {

    /*
    * This approach is inefficient for large data sets, as it uses additional memory and heap operations.
    *
    * Map creation: O(n)
    * Priority queue creation: O(k log k). This operation takes O(k log k) time, since each heap insertion requires O(log k) time, and a total of k operations are performed.
    * Extracting the maximum element: O(1)
    *
    * Time complexity:
    * O(n + k log k), where n is the vector length and k is the number of unique elements.
    *
    * Space complexity:
    * O(k), where k is the number of unique elements.
    */
    int Solution<v1>::majorityElement(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::unordered_map<int, int> majority_map;
        for (auto& num : nums) {
            majority_map[num]++;
        }

        auto cmp = [](const auto& a, const auto& b) {
            return a.second < b.second;
            };

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            decltype(cmp)> majority_pq(majority_map.begin(), majority_map.end());

        return majority_pq.top().first;
    }

    /*
    * Boyer-Moore Voting Algorithm
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    int Solution<v2>::majorityElement(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int candidate = 0;
        int count = 0;

        for (const auto& num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        count = 0;
        for (const auto& num : nums) {
            if (num == candidate) count++;
        }
        // the majority element is the element that appears more than ⌊n / 2⌋ times
        if (count > nums.size() / 2) return candidate;

        return candidate;
    }

}