#include "226_invert_binary_tree.h"
#include "class_version.h"

#include <stack>
#include <utility>

namespace _226 {

    /*
    * Iterative DFS (depth-first traversal) with a stack.
    *
    * Swaps left and right children at each node,
    * then pushes existing children onto the stack to continue down the tree.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h)
    */
    template <>
    SmartPointer::TreeNode* Solution<ver1>::invertTree(SmartPointer::TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        std::stack<SmartPointer::TreeNode*> nodes;
        nodes.emplace(root);

        while (!nodes.empty()) {
            SmartPointer::TreeNode* node = nodes.top();
            nodes.pop();

            std::swap(node->left, node->right);

            if (node->left) {
                nodes.emplace(node->left.get());
            }
            if (node->right) {
                nodes.emplace(node->right.get());
            }
        }

        return root;
    }

    /*
    * Recursive DFS: swap children at the current node, then invert both subtrees.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h), worst case O(n)
    */
    template <>
    SmartPointer::TreeNode* Solution<ver2>::invertTree(SmartPointer::TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        std::swap(root->left, root->right);

        Solution<ver2>::invertTree(root->left.get());
        Solution<ver2>::invertTree(root->right.get());

        return root;
    }

}
