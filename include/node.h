#pragma once

#include <memory>

/*
* Definition for a Node.
*
* See task: 138.
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class SmartNode {
public:
    int val;
    std::shared_ptr<SmartNode> next;
    std::weak_ptr<SmartNode> random;

    explicit SmartNode(int _val) : val(_val), next(nullptr), random() {}
};