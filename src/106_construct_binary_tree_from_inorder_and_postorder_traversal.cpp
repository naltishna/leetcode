#include "106_construct_binary_tree_from_inorder_and_postorder_traversal.h"

namespace _106 {

    /*
    * Recursive DFS (depth-first traversal) approach.
    *
    * Postorder gives the root last, so traverse it right-to-left.
    * Inorder still splits left/right subtrees around the root.
    *
    * 1) Build hashmap value, inorder index for O(1) lookups.
    * 2) Recursively: take next element from right end of postorder as root then find it in inorder,
    * then right subtree first, then left (order matters - mirrors postorder's R -> L traversal).
    *
    * Time complexity:
    * O(n) - each node visited once, O(1) lookup via hashmap
    *
    * Space complexity:
    * O(n) - hashmap + O(h) recursion stack, where h is tree height
    */
    RawPointer::TreeNode* Solution::buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        const int n = static_cast<int>(inorder.size());

        inorderIndexMap.clear();
        inorderIndexMap.reserve(n);
        postorderIndex = postorder.size() - 1;

        for (int i = 0; i < n; ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildSubtree(postorder, 0, n - 1);
    }

    RawPointer::TreeNode* Solution::buildSubtree(const std::vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        const int rootVal = preorder[postorderIndex--];
        const int mid = inorderIndexMap.at(rootVal);
        auto* root = new RawPointer::TreeNode(rootVal);

        root->right = buildSubtree(preorder, mid + 1, inEnd);
        root->left = buildSubtree(preorder, inStart, mid - 1);

        return root;
    }

}