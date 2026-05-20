#include "129_sum_root_to_leaf_numbers.h"

#include <stack>

namespace _129 {

    /*
    * Iterative DFS (depth-first traversal).
    *
    * It stores pairs of current node, current path value.
    * For each node, it calculates the next path value using current_value * 10 + child->val.
    * When a leaf node is reached, the path value is added to the total sum.
    *
    * Time complexity:
    * O(n) - visits every node exactly once
    *
    * Space complexity:
    * O(h) - stack holds at most h nodes
    */
    int Solution::sumNumbers(SmartPointer::TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sum = 0;
        std::stack<std::pair<SmartPointer::TreeNode*, int>> nodes;
        nodes.emplace(root, root->val);

        while (!nodes.empty()) {
            auto [node, value] = nodes.top();
            nodes.pop();

            if (!node->left && !node->right) {
                sum += value;
                continue;
            }

            if (node->left) {
                int numL = value * 10 + node->left->val;
                nodes.emplace(node->left.get(), numL);
            }

            if (node->right) {
                int numR = value * 10 + node->right->val;
                nodes.emplace(node->right.get(), numR);
            }
        }

        return sum;
    }

}
