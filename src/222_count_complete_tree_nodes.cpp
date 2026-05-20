#include "222_count_complete_tree_nodes.h"
#include "class_version.h"

#include <stack>

namespace _222 {

    /*
    * Iterative DFS (depth-first traversal).
    *
    * Uses an explicit stack to traverse every node exactly once.
    *
    * Time complexity:
    * O(n) — visits every node once
    *
    * Space complexity:
    * O(h) — stack holds at most one path from root to leaf, where h is tree height
    */
    template<>
    int Solution<ver1>::countNodes(SmartPointer::TreeNode* root) {
        if (!root) {
            return 0;
        }

        int count = 0;
        std::stack<SmartPointer::TreeNode*> nodes;
        nodes.emplace(root);

        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            count++;

            if (node->left) {
                nodes.emplace(node->left.get());
            }

            if (node->right) {
                nodes.emplace(node->right.get());
            }
        }

        return count;
    }

    /*
    * Recursive DFS.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h), worst case O(n)
    */
    template<>
    int Solution<ver2>::countNodes(SmartPointer::TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + countNodes(root->left.get()) + countNodes(root->right.get());
    }
}
