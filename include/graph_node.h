#pragma once

#include <vector>

/*
* Definition for a Node.
*
* See task: 133.
*/
class GraphNode {
public:
    int val;
    std::vector<GraphNode*> neighbors;

    GraphNode() : val(0) {}

    GraphNode(int _val) : val(_val) {}

    GraphNode(int _val, const std::vector<GraphNode*> _neighbors) : val(_val), neighbors(_neighbors) {}
};
