#include "530_minimum_absolute_difference_in_bst.h"

#include <algorithm>
#include <limits>
#include <stack>

namespace _530 {

    /*
    * Approach: In-order traversal (BST property).
    *
    * An in-order traversal of a BST visits nodes in strictly ascending order, it tracks the previously
    * visited node's value (prev) to find the minimum absolute difference between any two adjacent elements.
    * Tracks previous value and updates min difference at each step.
    *
    * Time complexity:
    * O(N) - every node visited once
    * 
    * Space complexity:
    * O(H) - stack depth equals tree height
    */
    int Solution::getMinimumDifference(SmartPointer::TreeNode* root) {
        int minDiff = std::numeric_limits<int>::max();
        int prev = 0;
        bool hasPrev = false;
        std::stack<SmartPointer::TreeNode*> stack;
        SmartPointer::TreeNode* node = root;

        while (node != nullptr || !stack.empty()) {
            while (node != nullptr) {
                stack.push(node);
                node = node->left.get();
            }

            node = stack.top();
            stack.pop();

            if (hasPrev) {
                minDiff = std::min(minDiff, node->val - prev);
            }
            else {
                hasPrev = true;
            }

            prev = node->val;
            node = node->right.get();
        }

        return minDiff;
    }

}
