#include "207_course_schedule.h"
#include "class_version.h"

#include <functional>
#include <queue>
#include <vector>

namespace _207 {

    /*
    * Approach: DFS cycle detection with three states.
    *
    * Build a directed graph prerequisite -> course and detect a back edge during DFS.
    *
    * Time complexity:
    * O(V + E)
    *
    * Space complexity:
    * O(V + E)
    */
    template<>
    bool Solution<ver1>::canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        const Graph graph = buildGraph(numCourses, prerequisites);

        enum class State {
            Unvisited,
            Visiting,
            Visited
        };

        std::vector<State> states(numCourses, State::Unvisited);

        std::function<bool(int)> hasCycle;
        hasCycle = [&](int node) -> bool {
            states[node] = State::Visiting;

            for (int next : graph[node]) {
                if (states[next] == State::Visiting) {
                    return true;
                }

                if (states[next] == State::Unvisited && hasCycle(next)) {
                    return true;
                }
            }

            states[node] = State::Visited;
            return false;
            };

        for (int i = 0; i < numCourses; ++i) {
            if (states[i] == State::Unvisited && hasCycle(i)) {
                return false;
            }
        }

        return true;
    }

    template<class V>
    Graph Solution<V>::buildGraph(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        Graph graph(numCourses);

        for (const auto& edge : prerequisites) {
            const int course = edge[0];
            const int prerequisite = edge[1];
            graph[prerequisite].push_back(course);
        }

        return graph;
    }

    /*
    * Approach: Kahn's algorithm (BFS topological sort).
    *
    * Build directed graph. Repeatedly take courses with indegree 0, decrement neighbors' in-degrees,
    * enqueue when they reach 0. If all courses are processed, there is no cycle.
    *
    * Time complexity:
    * O(V + E), V is the number of courses, E is the number of prerequisites
    *
    * Space complexity:
    * O(V + E)
    */
    template<>
    bool Solution<ver2>::canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        const Graph graph = buildGraph(numCourses, prerequisites);
        std::vector<int> indegree(numCourses);

        for (const auto& edge : prerequisites) {
            ++indegree[edge[0]];
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int processed = 0;
        while (!q.empty()) {
            const int node = q.front();
            q.pop();
            ++processed;

            for (int next : graph[node]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return processed == numCourses;
    }

}
