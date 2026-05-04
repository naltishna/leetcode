#include "452_minimum_number_of_arrows_to_burst_balloons.h"
#include "class_version.h"

#include <algorithm>

namespace _452 {

   /*
    * Merge overlapping balloons into a running interval list; answer = number of merged groups.
    *
    * Time complexity:
    * O(NlogN)
    *
    * Space complexity:
    * O(N)
    */
    template <>
    int Solution<ver1>::findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a.front() < b.front();
            });

        std::vector<std::vector<int>> result;
        result.push_back(points[0]);

        for (int i = 1; i < points.size(); ++i) {
            std::vector<int>& prev = result.back();
            if (prev[1] >= points[i][0]) {
                prev[0] = std::min(prev[0], points[i][0]);
                prev[1] = std::min(prev[1], points[i][1]);
            }
            else {
                result.push_back({ points[i] });
            }
        }

        return static_cast<int>(result.size());
    }

    /*
    * Sort balloons by start point, then greedily track the rightmost boundary (clusterRight) overlapping group.
    * If next balloon starts after clusterRight then no overlap, fire an arrow, start new cluster.
    * Otherwise, shrink clusterRight = min(clusterRight, balloon.end) to maintain the valid overlap window.
    *
    * The key insight: always shooting at the rightmost valid overlap point covers the maximum balloons with one arrow.
    *
    * Time complexity:
    * O(NlogN)
    *
    * Space complexity:
    * O(1)
    */
    template <>
    int Solution<ver2>::findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
            });

        int arrows = 1;
        int clusterRight = points[0][1];

        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i][0] > clusterRight) {
                ++arrows;
                clusterRight = points[i][1];
            }
            else {
                clusterRight = std::min(clusterRight, points[i][1]);
            }
        }

        return arrows;
    }

}
