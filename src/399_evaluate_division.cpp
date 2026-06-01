#include "399_evaluate_division.h"
#include "class_version.h"

#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace _399 {

    /*
    * Approach: weighted graph + DFS for each query.
    *
    * Build an undirected graph where edge u -> v stores u / v.
    * For each query, run DFS from the numerator and multiply edge weights along the path.
    *
    * Time complexity:
    * O(q * (V + E)), where q is the number of queries
    *
    * Space complexity:
    * O(V + E)
    */
    template<>
    std::vector<double> Solution<ver1>::calcEquation(const std::vector<std::vector<std::string>>& equations,
        const std::vector<double>& values,
        const std::vector<std::vector<std::string>>& queries) {
        const Graph graph = buildGraph(equations, values);
        std::vector<double> result;
        result.reserve(queries.size());

        std::function<bool(const std::string&, const std::string&, double,
            const Graph&, std::unordered_set<std::string>&, double&)> dfs;
        dfs = [&](const std::string& curr, const std::string& target, double weight,
            const Graph& g, std::unordered_set<std::string>& visited, double& answer) -> bool {
                if (curr == target) {
                    answer = weight;
                    return true;
                }

                visited.insert(curr);

                for (const auto& [next, edgeWeight] : g.at(curr)) {
                    if (!visited.contains(next)) {
                        if (dfs(next, target, weight * edgeWeight, g, visited, answer)) {
                            return true;
                        }
                    }
                }

                return false;
            };

        for (const auto& query : queries) {
            const std::string& start = query[0];
            const std::string& end = query[1];

            if (!graph.contains(start) || !graph.contains(end)) {
                result.push_back(-1.0);
                continue;
            }

            if (start == end) {
                result.push_back(1.0);
                continue;
            }

            std::unordered_set<std::string> visited;
            double answer = -1.0;
            dfs(start, end, 1.0, graph, visited, answer);
            result.push_back(answer);
        }

        return result;
    }

    template<class V>
    Graph Solution<V>::buildGraph(const std::vector<std::vector<std::string>>& equations,
                                  const std::vector<double>& values) {
        Graph graph;

        for (size_t i = 0; i < equations.size(); ++i) {
            const std::string& left = equations[i][0];
            const std::string& right = equations[i][1];
            const double weight = values[i];

            graph[left].emplace_back(right, weight);
            graph[right].emplace_back(left, 1.0 / weight);
        }

        return graph;
    }

    /*
    * Approach: weighted graph + BFS for each query.
    *
    * Build a weighted directed graph where each equation a/b = k adds edges a->b (k) and b->a (1/k).
    * For each query, BFS from source to target, multiplying edge weights along the path.
    *
    * Time complexity:
    * O(q * (V + E)), q is the number of queries
    *
    * Space complexity:
    * O(V + E), V is the number of variables, E is the number of equations
    */
    template<>
    std::vector<double> Solution<ver2>::calcEquation(const std::vector<std::vector<std::string>>& equations,
                                                     const std::vector<double>& values,
                                                     const std::vector<std::vector<std::string>>& queries) {
        const Graph graph = buildGraph(equations, values);
        std::vector<double> result;
        result.reserve(queries.size());

        for (const auto& query : queries) {
            const std::string& start = query[0];
            const std::string& end = query[1];

            if (!graph.contains(start) || !graph.contains(end)) {
                result.push_back(-1.0);
                continue;
            }

            if (start == end) {
                result.push_back(1.0);
                continue;
            }

            std::queue<std::pair<std::string, double>> q;
            std::unordered_set<std::string> visited;
            double answer = -1.0;
            bool found = false;

            q.push({ start, 1.0 });
            visited.insert(start);

            while (!q.empty() && !found) {
                const auto [curr, weight] = q.front();
                q.pop();

                for (const auto& [next, edgeWeight] : graph.at(curr)) {
                    if (visited.contains(next)) {
                        continue;
                    }

                    const double nextWeight = weight * edgeWeight;

                    if (next == end) {
                        answer = nextWeight;
                        found = true;
                        break;
                    }

                    visited.insert(next);
                    q.push({ next, nextWeight });
                }
            }

            result.push_back(answer);
        }

        return result;
    }

}
