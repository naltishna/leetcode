#include "57_insert_interval.h"

#include <algorithm>

namespace _57 {

    /*
    * Processes intervals in three distinct passes.
    *
    * Phase 1 — copy non-overlapping left:
    * Add all intervals that end before newInterval starts (intervals[i][1] < start). These are untouched.
    *
    * Phase 2 — merge overlapping:
    * While intervals overlap with newInterval (intervals[i][0] <= end), expand the merged interval:
    * start = min(start, intervals[i][0])
    * end = max(end, intervals[i][1])
    * Then push the single merged result.
    *
    * Phase 3 — copy non-overlapping right:
    * Append remaining intervals as-is.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    std::vector<std::vector<int>> Solution::insert(std::vector<std::vector<int>>& intervals,
                                                   const std::vector<int>& newInterval) {
        if (newInterval.size() < 2) {
            return intervals;
        }
        if (intervals.empty()) {
            return { newInterval };
        }

        std::vector<std::vector<int>> res;
        res.reserve(intervals.size() + 1);

        const int n = static_cast<int>(intervals.size());
        int start = newInterval[0];
        int end = newInterval[1];
        int i = 0;

        while (i < n && start > intervals[i][1]) {
            res.push_back(intervals[i]);
            ++i;
        }

        while (i < n && end >= intervals[i][0]) {
            start = std::min(start, intervals[i][0]);
            end = std::max(end, intervals[i][1]);
            ++i;
        }
        res.push_back({ start, end });

        while (i < n) {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }

}
