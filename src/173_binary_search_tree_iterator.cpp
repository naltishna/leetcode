#include "173_binary_search_tree_iterator.h"

namespace _173 {

    /*
    * Iterative in-order traversal approach.
    *
    * Simulates inorder traversal (left -> node -> right) using a stack.
    * On construction, pushes all leftmost nodes. Each next() pops the top node,
    * then pushes the leftmost chain of its right subtree.
    *
    * Time complexity:
    * O(1) amortized for next() and hasNext()
    *
    * Space complexity:
    * O(h) - stack height, worst case O(n)
    */
    BSTIterator::BSTIterator(RawPointer::TreeNode* root) {
        pushLeft(root);
    }

    int BSTIterator::next() {
        RawPointer::TreeNode* node = stack.top();
        stack.pop();
        pushLeft(node->right);
        return node->val;
    }

    bool BSTIterator::hasNext() {
        return !stack.empty();
    }

    void BSTIterator::pushLeft(RawPointer::TreeNode* node) {
        while (node != nullptr) {
            stack.push(node);
            node = node->left;
        }
    }

}
