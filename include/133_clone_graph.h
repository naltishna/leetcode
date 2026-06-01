/*
https://leetcode.com/problems/clone-graph/description/

133. Clone Graph

Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (vector) of its neighbors.

class Node {
public:
    int val;
    vector<Node *> neighbors;
};

Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1,
the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of
neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to
the cloned graph.

Example 1:
Input: adjList = [[2,4],[1,3],[2],[1,3]]
Output: [[2,4],[1,3],[2],[1,3]]

Example 2:
Input: adjList = [[]]
Output: [[]]

Example 3:
Input: adjList = []
Output: []

Constraints:
The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
Node is null or Node.val == 1 if non-empty.
The graph is connected if Node is not null.
There are no repeated edges and no self-loops in the graph.
The graph is undirected.
*/

#pragma once

#include "graph_node.h"

namespace _133 {

    template <class V>
    class Solution {
    public:
        GraphNode* cloneGraph(GraphNode* node);
    };

}
