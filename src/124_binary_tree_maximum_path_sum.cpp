#include "124_binary_tree_maximum_path_sum.h"
#include "class_version.h"

#include <algorithm>
#include <limits>
#include <stack>
#include <unordered_map>

namespace _124 {

    /*
    * Iterative post-order DFS.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    int Solution<ver1>::maxPathSum(SmartPointer::TreeNode* root) {
        if (!root) {
            return 0;
        }

        int maxSum = std::numeric_limits<int>::min();
        std::unordered_map<SmartPointer::TreeNode*, int> gain;
        std::stack<std::pair<SmartPointer::TreeNode*, bool>> nodes;

        nodes.emplace(root, false);

        while (!nodes.empty()) {
            auto [node, processed] = nodes.top();
            nodes.pop();

            if (!processed) {
                nodes.emplace(node, true);

                if (node->right) {
                    nodes.emplace(node->right.get(), false);
                }

                if (node->left) {
                    nodes.emplace(node->left.get(), false);
                }

                continue;
            }

            const int leftGain = node->left ? std::max(0, gain[node->left.get()]) : 0;
            const int rightGain = node->right ? std::max(0, gain[node->right.get()]) : 0;

            maxSum = std::max(maxSum, node->val + leftGain + rightGain);
            gain[node] = node->val + std::max(leftGain, rightGain);
        }

        return maxSum;
    }

    /*
    * Recursive post-order DFS: maxGain returns best downward branch; maxSum updated at each node.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h), worst case O(n)
    */
    int Solution<ver2>::maxPathSum(SmartPointer::TreeNode* root) {
        maxGainRecursive(root);

        return maxSum;
    }

    template <>
    int Solution<ver2>::maxGainRecursive(SmartPointer::TreeNode* node) {
        if (!node) {
            return 0;
        }

        const int leftGain = std::max(0, maxGainRecursive(node->left.get()));
        const int rightGain = std::max(0, maxGainRecursive(node->right.get()));

        maxSum = std::max(maxSum, node->val + leftGain + rightGain);

        return node->val + std::max(leftGain, rightGain);
    }

}
