#include "110_balanced_binary_tree.h"

#include <algorithm>
#include <cmath>

namespace _110 {

    /*
    * The algorithm checks whether a binary tree is balanced by recursively passing each node.
    * For every node, it calculates the heights of its left and right subtrees and compares them.
    * If the difference in their heights exceeds one, the tree is considered unbalanced.

    * Complexity
    * Time complexity:
    * O(N), where N - nodes number

    * Space complexity:
    * O(H), height H is equal to the number of nodes N
    *
    */
    bool Solution::isBalanced(RawPointer::TreeNode* root) {
        return checkBalance(root) >= 0;
    }

    /*
    * Returns a tree height.
    */
    int Solution::checkBalance(RawPointer::TreeNode* node) {
        if (!node) {
            return 0;
        }

        // check left and right subtrees
        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1 || std::abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // the height of the current subtree is equal to the max depth of child nodes plus one
        return 1 + std::max(leftHeight, rightHeight);
    }

    /*
    * Recursively removes all nodes in a subtree.
    */
    void Solution::destroy(RawPointer::TreeNode* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

}