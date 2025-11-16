#include "56_merge_intervals.h"

#include <algorithm>

namespace _56 {

    std::vector<std::vector<int>> Solution::merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty() || intervals.size() == 1) {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
                return a.front() < b.front();
            });

        std::vector<std::vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int>& prev = result.back();
            if (prev[1] >= intervals[i][0]) {
                prev[1] = std::max(prev[1], intervals[i][1]);
            }
            else {
                result.push_back({ intervals[i] });
            }
        }
        return result;
    }

}
