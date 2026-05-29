#include "46_permutations.h"
#include "class_version.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace _46 {

    /*
    * Approach: Backtracking.
    *
    * Builds each permutation by trying every unused element at the current position.
    *
    * Time complexity:
    * O(n! * n), where n is the number of elements (n! permutations, each takes O(n) to copy)
    *
    * Space complexity:
    * O(n) - recursion depth, current permutation, and used flags (excluding output)
    */
    template<>
    std::vector<std::vector<int>> Solution<ver1>::permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> used(nums.size(), false);

        std::function<void()> backtrack = [&]() {
            if (current.size() == nums.size()) {
                result.push_back(current);
                return;
            }

            for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
                if (used[i]) {
                    continue;
                }

                used[i] = true;
                current.push_back(nums[i]);
                backtrack();
                current.pop_back();
                used[i] = false;
            }
            };

        backtrack();

        return result;
    }

    /*
    * Approach: Iterative next-permutation generation.
    *
    * Sorts nums and repeatedly advances to the next lexicographic permutation
    * using std::next_permutation until all are generated.
    *
    * Time complexity:
    * O(N! · N) - N! permutations, each takes O(N) to copy
    *
    * Space complexity:
    * O(N! · N) - storing all permutations
    */
    template<>
    std::vector<std::vector<int>> Solution<ver2>::permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;

        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return result;
    }

    /*
    * Approach: Swap-based backtracking.
    *
    * Fixes each position by swapping nums[start] with nums[i] for i >= start,
    * recurses on the next position, then swaps back.
    *
    * Time complexity:
    * O(n! * n)
    *
    * Space complexity:
    * O(n) - recursion depth (excluding output)
    */
    template<>
    std::vector<std::vector<int>> Solution<ver3>::permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;

        std::function<void(int)> backtrack = [&](int start) {
            if (start == static_cast<int>(nums.size())) {
                result.push_back(nums);
                return;
            }

            for (int i = start; i < static_cast<int>(nums.size()); ++i) {
                std::swap(nums[start], nums[i]);
                backtrack(start + 1);
                std::swap(nums[start], nums[i]);
            }
            };

        backtrack(0);

        return result;
    }

    /*
    * Approach: Iterative insertion expansion.
    *
    * Starts with one-element permutations and, for each next number, inserts it
    * into every possible position of every existing permutation.
    *
    * Time complexity:
    * O(n! * n^2)
    *
    * Space complexity:
    * O(n! * n) - intermediate permutations (excluding output)
    */
    template<>
    std::vector<std::vector<int>> Solution<ver4>::permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;

        if (nums.empty()) {
            return result;
        }

        result.push_back({ nums[0] });

        for (std::size_t index = 1; index < nums.size(); ++index) {
            std::vector<std::vector<int>> next;

            for (const auto& perm : result) {
                for (std::size_t pos = 0; pos <= perm.size(); ++pos) {
                    std::vector<int> candidate = perm;
                    candidate.insert(candidate.begin() + static_cast<std::ptrdiff_t>(pos), nums[index]);
                    next.push_back(std::move(candidate));
                }
            }

            result = std::move(next);
        }

        return result;
    }

}
