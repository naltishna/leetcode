#include "39_combination_sum.h"
#include "class_version.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace _39 {

    /*
    * Approach: Backtracking.
    *
    * Recursively builds combinations, allowing reuse of the same element (backtrack(i, ...)).
    * Array sorted upfront so the loop can break early when candidates[i] > remaining.
    *
    * Time complexity:
    * O(2^target)
    *
    * Space complexity:
    * O(target) - recursion depth and current combination (excluding output)
    */
    template<>
    std::vector<std::vector<int>> Solution<ver1>::combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        std::sort(candidates.begin(), candidates.end());

        std::function<void(int, int)> backtrack = [&](int start, int remaining) {
            if (remaining == 0) {
                result.push_back(current);
                return;
            }

            for (int i = start; i < static_cast<int>(candidates.size()); ++i) {
                if (candidates[i] > remaining) {
                    break;
                }

                current.push_back(candidates[i]);
                backtrack(i, remaining - candidates[i]);
                current.pop_back();
            }
            };

        backtrack(0, target);

        return result;
    }

    /*
    * Approach: Iterative backtracking with explicit stack.
    *
    * Simulates recursive DFS using a stack of frames {start, remaining, current}.
    * Candidates are pushed in reverse order to preserve the same result order as ver1.
    *
    * Time complexity:
    * O(2^target) in the worst case (excluding output)
    *
    * Space complexity:
    * O(target / min(candidates)) - stack depth and current combination (excluding output)
    */
    template<>
    std::vector<std::vector<int>> Solution<ver2>::combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;

        struct Frame {
            int start;
            int remaining;
            std::vector<int> current;
        };

        std::sort(candidates.begin(), candidates.end());

        std::vector<Frame> stack;
        stack.push_back({ 0, target, {} });

        while (!stack.empty()) {
            Frame frame = std::move(stack.back());
            stack.pop_back();

            if (frame.remaining == 0) {
                result.push_back(frame.current);
                continue;
            }

            for (int i = static_cast<int>(candidates.size()) - 1; i >= frame.start; --i) {
                if (candidates[i] > frame.remaining) {
                    continue;
                }

                std::vector<int> next = frame.current;
                next.push_back(candidates[i]);
                stack.push_back({ i, frame.remaining - candidates[i], std::move(next) });
            }
        }

        return result;
    }

}
