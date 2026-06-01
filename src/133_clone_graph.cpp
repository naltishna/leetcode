#include "133_clone_graph.h"
#include "class_version.h"

#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

namespace _133 {

    /*
    * Approach: BFS with parallel vectors.
    *
    * First pass collects original nodes and creates clones in the same order.
    * Second pass wires clone neighbors by searching the original node index with std::find.
    *
    * Time complexity:
    * O(n^2), where n is the number of nodes
    *
    * Space complexity:
    * O(n)
    */
    template<>
    GraphNode* Solution<ver1>::cloneGraph(GraphNode* node) {
        if (!node) {
            return nullptr;
        }

        std::vector<GraphNode*> nodes;
        std::vector<GraphNode*> cloneNodes;
        std::vector<GraphNode*> queue{ node };
        size_t head = 0;

        while (head < queue.size()) {
            GraphNode* curr = queue[head++];
            if (std::find(nodes.begin(), nodes.end(), curr) != nodes.end()) {
                continue;
            }

            cloneNodes.push_back(new GraphNode(curr->val));
            nodes.push_back(curr);

            for (GraphNode* neighbor : curr->neighbors) {
                if (std::find(nodes.begin(), nodes.end(), neighbor) == nodes.end()) {
                    queue.push_back(neighbor);
                }
            }
        }

        for (size_t i = 0; i < nodes.size(); ++i) {
            for (GraphNode* neighbor : nodes[i]->neighbors) {
                const size_t j = static_cast<size_t>(
                    std::find(nodes.begin(), nodes.end(), neighbor) - nodes.begin());
                cloneNodes[i]->neighbors.push_back(cloneNodes[j]);
            }
        }

        return cloneNodes[0];
    }

    /*
    * Approach: BFS + hash map from original node to clone.
    *
    * Each node is cloned once when first discovered. Neighbors are wired in the same pass using O(1) map lookups.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    template<>
    GraphNode* Solution<ver2>::cloneGraph(GraphNode* node) {
        if (!node) {
            return nullptr;
        }

        std::unordered_map<GraphNode*, GraphNode*> cloned;
        std::queue<GraphNode*> q;
        q.push(node);
        cloned[node] = new GraphNode(node->val);

        while (!q.empty()) {
            GraphNode* curr = q.front();
            q.pop();

            for (GraphNode* neighbor : curr->neighbors) {
                if (!cloned.contains(neighbor)) {
                    cloned[neighbor] = new GraphNode(neighbor->val);
                    q.push(neighbor);
                }

                cloned[curr]->neighbors.push_back(cloned[neighbor]);
            }
        }

        return cloned[node];
    }

    /*
    * Approach: DFS + hash map from original node to clone.
    *
    * Recursively clone each node on first visit, store it in the map, then wire neighbors
    * by recursing into them. Already cloned nodes are returned from the map.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    template<>
    GraphNode* Solution<ver3>::cloneGraph(GraphNode* node) {
        if (!node) {
            return nullptr;
        }

        std::unordered_map<GraphNode*, GraphNode*> cloned;

        std::function<GraphNode* (GraphNode*)> dfs = [&](GraphNode* curr) -> GraphNode* {
            if (cloned.contains(curr)) {
                return cloned[curr];
            }

            GraphNode* copy = new GraphNode(curr->val);
            cloned[curr] = copy;

            for (GraphNode* neighbor : curr->neighbors) {
                copy->neighbors.push_back(dfs(neighbor));
            }

            return copy;
            };

        return dfs(node);
    }

}
