/*
https://leetcode.com/problems/course-schedule/description/

207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array
prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

#pragma once

#include <vector>

namespace _207 {

    using Graph = std::vector<std::vector<int>>;

    template <class V>
    class Solution {
        static Graph buildGraph(int numCourses, const std::vector<std::vector<int>>& prerequisites);
    public:
        bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites);
    };

}
