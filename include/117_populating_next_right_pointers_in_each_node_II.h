/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

117. Populating Next Right Pointers in Each Node II

Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,3,2,#,4,5,7,#]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1,#]

Constraints:
The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100
*/

#pragma once

namespace _117 {

    struct Node {
        int val;
        Node* left;
        Node* right;
        Node* next;

        explicit Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    };

    template <class V>
    class Solution {
    public:
        Node* connect(Node* root);
    };

}
