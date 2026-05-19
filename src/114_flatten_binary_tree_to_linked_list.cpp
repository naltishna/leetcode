#include "114_flatten_binary_tree_to_linked_list.h"
#include "class_version.h"

namespace _114 {

    /*
    * Post-order flatten: flatten subtrees, then splice left chain onto the right of root.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h), worst case O(n)
    */
    template <>
    void Solution<ver1>::flatten(RawPointer::TreeNode* root) {
        if (!root) {
            return;
        }

        Solution<ver1>::flatten(root->left);
        Solution<ver1>::flatten(root->right);

        RawPointer::TreeNode* rightSubtree = root->right;
        root->right = root->left;
        root->left = nullptr;

        RawPointer::TreeNode* tail = root;
        while (tail->right) {
            tail = tail->right;
        }
        tail->right = rightSubtree;
    }

    /*
    * Approach: Morris Traversal (Iterative In-place Flattening).
    *
    * The algorithm iterates through the tree, and for each node that has a left subtree:
    * - Finds the rightmost node of the left subtree (the "tail").
    * - Connects that tail to the current node's right subtree.
    * - Moves the entire left subtree to the right.
    * - Nullifies the left pointer.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template <>
    void Solution<ver2>::flatten(RawPointer::TreeNode* root) {
        for (RawPointer::TreeNode* curr = root; curr; curr = curr->right) {
            if (!curr->left) {
                continue;
            }

            RawPointer::TreeNode* tail = curr->left;
            while (tail->right) {
                tail = tail->right;
            }

            tail->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
    }

}
