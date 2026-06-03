#include "210_course_schedule_II.h"
#include "class_version.h"

#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

namespace _210 {

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
    * Take courses with indegree 0, append them to the answer, and relax neighbors.
    * If not all courses are processed, a cycle exists.
    *
    * Same as 207 task but records the processing order. If all nodes processed -> return order,
    * otherwise cycle detected -> return {}.
    *
    * Time complexity:
    * O(V + E), V is the number of courses, E is the number of prerequisites
    *
    * Space complexity:
    * O(V + E)
    */
    template<>
    std::vector<int> Solution<ver1>::findOrder(int numCourses,
        const std::vector<std::vector<int>>& prerequisites) {
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

        std::vector<int> order;
        order.reserve(numCourses);

        while (!q.empty()) {
            const int node = q.front();
            q.pop();
            order.push_back(node);

            for (int next : graph[node]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (order.size() != numCourses) {
            return {};
        }

        return order;
    }

    /*
    * Approach: DFS post-order + reverse.
    *
    * Append a node after visiting all outgoing edges. Reverse the post-order to get a valid schedule.
    * A back edge means a cycle.
    *
    * Time complexity:
    * O(V + E)
    *
    * Space complexity:
    * O(V + E)
    */
    template<>
    std::vector<int> Solution<ver2>::findOrder(int numCourses,
        const std::vector<std::vector<int>>& prerequisites) {
        const Graph graph = buildGraph(numCourses, prerequisites);

        enum class State {
            Unvisited,
            Visiting,
            Visited
        };

        std::vector<State> states(numCourses, State::Unvisited);
        std::vector<int> order;
        order.reserve(numCourses);
        bool hasCycle = false;

        std::function<void(int)> dfs;
        dfs = [&](int node) {
            states[node] = State::Visiting;

            for (int next : graph[node]) {
                if (states[next] == State::Visiting) {
                    hasCycle = true;
                    return;
                }

                if (states[next] == State::Unvisited) {
                    dfs(next);

                    if (hasCycle) {
                        return;
                    }
                }
            }

            states[node] = State::Visited;
            order.push_back(node);
            };

        for (int i = 0; i < numCourses && !hasCycle; ++i) {
            if (states[i] == State::Unvisited) {
                dfs(i);
            }
        }

        if (hasCycle || static_cast<int>(order.size()) != numCourses) {
            return {};
        }

        std::reverse(order.begin(), order.end());

        return order;
    }

}
