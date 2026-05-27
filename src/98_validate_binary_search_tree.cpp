#include "98_validate_binary_search_tree.h"

#include <stack>

namespace _98 {

    /*
    * Approach: Iterative in-order traversal.
    *
    * Tracks previous value and returns false immediately if current node violates the ascending order.
    *
    * Time complexity:
    * O(N) - every node visited once
    *
    * Space complexity:
    * O(H) - stack depth equals tree height
    */
    bool Solution::isValidBST(SmartPointer::TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

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

            if (hasPrev && node->val <= prev) {
                return false;
            }

            hasPrev = true;
            prev = node->val;
            node = node->right.get();
        }

        return true;
    }

}
