#include "80_remove_duplicates_from_sorted_array_II.h"

#include <unordered_map>

namespace _80 {
    /*
    * std::unordered_map helps to track the number of occurrences of each element in the array.
    * This approach creates an intermediate result vector, which increases memory consumption may negatively impact performance.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    template<>
    int Solution<_80_v1>::removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::unordered_map<int, int> freqMap;
        std::vector<int> result;

        for (auto num : nums) {
            // each element appears at most twice
            if (freqMap[num] < 2) {
                result.push_back(num);
                freqMap[num]++;
            }
        }

        nums.swap(result);
        return nums.size();
    }

    /*
    * Use two-pointers approach.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<_80_v2>::removeDuplicates(std::vector<int>& nums) {
        const size_t n = nums.size();
        if (n <= 2) {
            return n;
        }

        size_t j = 2;
        for (size_t i = 2; i < n; ++i) {
            // verifies that the element is not equal to the penultimate recorded element
            if (nums[j - 2] != nums[i]) {
                nums[j++] = nums[i];
            }
        }

        nums.erase(nums.begin() + j, nums.end());

        return nums.size();
    }

}