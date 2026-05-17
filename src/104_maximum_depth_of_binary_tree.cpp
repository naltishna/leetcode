#include "104_maximum_depth_of_binary_tree.h"
#include "class_version.h"

#include <algorithm>
#include <stack>
#include <utility>

namespace _104 {

    /*
    * Recursive DFS.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h), worst case O(n)
    */
    template <>
    int Solution<ver1>::maxDepth(SmartPointer::TreeNode* root) {
        if (!root) {
            return 0;
        }

        const int leftHeight = Solution<ver1>::maxDepth(root->left.get());
        const int rightHeight = Solution<ver1>::maxDepth(root->right.get());

        return 1 + std::max(leftHeight, rightHeight);
    }

    /*
    * Iterative DFS (depth-first traversal).
    *
    * Tracks (node, depth) pairs. At each step pops a node, updates the running max,
    * then pushes right then left child (left pushed last and processed first,
    * mimicking recursive DFS order).
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h)
    */
    template <>
    int Solution<ver2>::maxDepth(SmartPointer::TreeNode* root) {
        if (!root) {
            return 0;
        }

        int maxDepth = 0;
        std::stack<std::pair<SmartPointer::TreeNode*, int>> nodes;
        nodes.emplace(root, 1);

        while (!nodes.empty()) {
            auto [node, depth] = nodes.top();
            nodes.pop();

            maxDepth = std::max(maxDepth, depth);

            if (node->right) {
                nodes.emplace(node->right.get(), depth + 1);
            }

            if (node->left) {
                nodes.emplace(node->left.get(), depth + 1);
            }
        }

        return maxDepth;
    }

}
