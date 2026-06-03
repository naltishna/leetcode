/*
https://leetcode.com/problems/course-schedule-ii/description/

210. Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array
prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them.
If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs prerequisites[i] are unique.
The input graph is a directed acyclic graph.
*/

#pragma once

#include <vector>

namespace _210 {

    using Graph = std::vector<std::vector<int>>;

    template <class V>
    class Solution {
        static Graph buildGraph(int numCourses, const std::vector<std::vector<int>>& prerequisites);

    public:
        std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>>& prerequisites);
    };

}
