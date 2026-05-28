#include "77_combinations.h"
#include "class_version.h"

#include <functional>
#include <vector>

namespace _77 {

    /*
    * Approach: Backtracking.
    *
    * Builds combinations recursively. At each step picks a number from start to n,
    * adds it to current combination, recurses, then removes it. Stops when current reaches size k.
    *
    * Time complexity:
    * O(C(n,k) * k) - C(n,k) combinations, each takes O(k) to copy
    *
    * Space complexity:
    * O(k) - recursion depth + current combination (excluding output)
    */
    template<>
    std::vector<std::vector<int>> Solution<ver1>::combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        // Builds each combination by choosing the next number greater than the previous one.
        std::function<void(int)> backtrack = [&](int start) {
            if (static_cast<int>(current.size()) == k) {
                result.push_back(current);

                return;
            }

            for (int i = start; i <= n; ++i) {
                current.push_back(i);
                backtrack(i + 1);
                current.pop_back();
            }
        };

        backtrack(1);

        return result;
    }

    /*
    * Approach: Iterative next-combination generation.
    *
    * Starts from [1, 2, ..., k] and repeatedly advances to the next lexicographic
    * combination until the last one is reached.
    *
    * Time complexity:
    * O(C(n, k) * k)
    *
    * Space complexity:
    * O(k) - current combination
    */
    template<>
    std::vector<std::vector<int>> Solution<ver2>::combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current(k);

        for (int i = 0; i < k; ++i) {
            current[i] = i + 1;
        }

        while (true) {
            result.push_back(current);

            int index = k - 1;
            while (index >= 0 && current[index] == n - k + index + 1) {
                --index;
            }

            if (index < 0) {
                break;
            }

            ++current[index];
            for (int j = index + 1; j < k; ++j) {
                current[j] = current[j - 1] + 1;
            }
        }

        return result;
    }

}
