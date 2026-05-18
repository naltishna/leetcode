#include "105_construct_binary_tree_from_preorder_and_inorder_traversal.h"

namespace _105 {

    /*
    * Iterative DFS (depth-first traversal) approach.
    *
    * Uses the fact that preorder traversal always gives the root first,
    * and inorder splits into left/right subtrees around the root.
    *
    * Build a hashmap value, inorder index for O(1) root lookups.
    * Recursively: take next preorder element as root then find it in inorder,
    * then left subtree is everything to its left, right - to its right.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n) — hashmap + O(h) recursion stack, where h is tree height (O(log n) balanced, O(n) worst)
    */
    RawPointer::TreeNode* Solution::buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        const int n = static_cast<int>(inorder.size());

        inorderIndexMap.clear();
        inorderIndexMap.reserve(n);
        preorderIndex = 0;

        for (int i = 0; i < n; ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildSubtree(preorder, 0, n - 1);
    }

    RawPointer::TreeNode* Solution::buildSubtree(const std::vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        const int rootVal = preorder[preorderIndex++];
        const int mid = inorderIndexMap.at(rootVal);
        auto* root = new RawPointer::TreeNode(rootVal);

        root->left = buildSubtree(preorder, inStart, mid - 1);
        root->right = buildSubtree(preorder, mid + 1, inEnd);

        return root;
    }

}