/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

653. Two Sum IV - Input is a Binary Search Tree (BST)

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-10^4 <= Node.val <= 10^4
root is guaranteed to be a valid binary search tree.
-10^5 <= k <= 10^5
*/

#pragma once

#include "tree_node.h"
#include <vector>

namespace _653 {

    template<typename Version>
    class Solution {
    public:
        bool findTarget(SmartPointer::TreeNode* root, int k);
    };

}

struct  _653_BFS_ver {};
struct  _653_memory_optimal_ver {};

namespace _653_two_ptr {

    class Solution {
    public:
        bool findTarget(SmartPointer::TreeNode* root, int k);

    private:
        void inorder(SmartPointer::TreeNode* node, std::vector<int>& sorted);
    };

}