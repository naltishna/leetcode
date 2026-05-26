#include "502_ipo.h"

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

namespace _502 {

    /*
    * Approach: Greedy + max-heap.
    *
    * Sort projects by required capital. Repeatedly add all affordable projects
    * to a max-heap of profits and pick the most profitable one.
    *
    * Time complexity:
    * O(n log n) — sorting + each project pushed/popped from heap once
    *
    * Space complexity:
    * O(n) — projects array + heap
    */
    int Solution::findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        const int n = static_cast<int>(profits.size());
        std::vector<std::pair<int, int>> projects;
        projects.reserve(n);

        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        std::sort(projects.begin(), projects.end());

        std::priority_queue<int> maxProfit;
        int i = 0;

        while (k-- > 0) {
            while (i < n && projects[i].first <= w) {
                maxProfit.push(projects[i].second);
                ++i;
            }

            if (maxProfit.empty()) {
                break;
            }

            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }

}
