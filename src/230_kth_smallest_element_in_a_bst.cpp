#include "230_kth_smallest_element_in_a_bst.h"

#include <stack>

namespace _230 {

    /*
    * Approach: Iterative in-order traversal.
    *
    * Counts down k at each visited node, returns immediately when k reaches 0,
    * no need to traverse the entire tree.
    *
    * Time complexity:
    * O(H + k) - H is tree height
    *
    * Space complexity:
    * O(H) - stack depth equals tree height
    */
    int Solution::kthSmallest(SmartPointer::TreeNode* root, int k) {
        std::stack<SmartPointer::TreeNode*> stack;
        SmartPointer::TreeNode* node = root;

        while (node != nullptr || !stack.empty()) {
            while (node != nullptr) {
                stack.push(node);
                node = node->left.get();
            }

            node = stack.top();
            stack.pop();

            if (--k == 0) {
                return node->val;
            }

            node = node->right.get();
        }

        return -1;
    }

}
