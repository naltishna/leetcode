#include "56_merge_intervals.h"

#include <algorithm>

namespace _56 {

    /*
    * The incoming intervals are initially sorted in ascending order by their starting point.
    * This simplifies the process of merging neighboring intervals, as adjacent intervals become neighboring elements in the sorted list.
    * After sorting, a single pass is performed over the list, starting from the second interval.
    * The algorithm checks whether the current interval overlaps with the previous one.
    * If yes, it merges them by expanding the boundaries of the current interval.
    * If not, a new interval is added to the resulting list.
    * 
    * Complexity
    * Time complexity:
    * O(NlogN)
    * 
    * Space complexity:
    * O(N)
    */
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
