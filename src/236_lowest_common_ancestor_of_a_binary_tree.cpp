#include "236_lowest_common_ancestor_of_a_binary_tree.h"
#include "class_version.h"

#include <stack>
#include <unordered_map>
#include <unordered_set>

namespace _236 {

    /*
    * Recursive post-order DFS (depth-first traversal).
    *
    * A node is the LCA when targets are found on opposite sides, or when the node itself is one of the targets.
    *
    * Each call returns:
    * - nullptr  if neither p nor q is in this subtree;
    * - p or q   if only that node was found (the other is elsewhere);
    * - LCA      if both targets are in this subtree.
    *
    * When left and right are both non-null, p and q sit in different subtrees of root,
    * so root is the lowest common ancestor.
    *
    * Time complexity:
    * O(N) - visits every node at most once
    *
    * Space complexity:
    * O(H) - call stack depth equals tree height
    */
    template <>
    RawPointer::TreeNode* Solution<ver1>::lowestCommonAncestor(
        RawPointer::TreeNode* root,
        RawPointer::TreeNode* p,
        RawPointer::TreeNode* q) {
        // Return nullptr (target nodes not found in this branch).
        // If the current node is p or q, return it — signals to callers that one target was found.
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Result of searching the left and right subtrees.
        RawPointer::TreeNode* const left = lowestCommonAncestor(root->left, p, q);
        RawPointer::TreeNode* const right = lowestCommonAncestor(root->right, p, q);

        // p is in the left subtree and q is in the right subtree (or vice versa):
        // root is the split point — the LCA.
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // Both targets (or the single found one) lie on the same side: return that side.
        return left != nullptr ? left : right;
    }

    /*
    * Iterative DFS with a parent map: record parents until both p and q are seen,
    * collect p's ancestors, then walk q upward to the first common node.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    template <>
    RawPointer::TreeNode* Solution<ver2>::lowestCommonAncestor(RawPointer::TreeNode* root, RawPointer::TreeNode* p, RawPointer::TreeNode* q) {
        std::unordered_map<RawPointer::TreeNode*, RawPointer::TreeNode*> parent;
        // root is the parent of itself
        parent[root] = nullptr;

        std::stack<RawPointer::TreeNode*> nodes;
        nodes.push(root);

        // find the parent of p and q
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            RawPointer::TreeNode* node = nodes.top();
            nodes.pop();

            if (node->left != nullptr && parent.find(node->left) == parent.end()) {
                parent[node->left] = node;
                nodes.push(node->left);
            }

            if (node->right != nullptr && parent.find(node->right) == parent.end()) {
                parent[node->right] = node;
                nodes.push(node->right);
            }
        }

        // find the ancestors of p
        std::unordered_set<RawPointer::TreeNode*> ancestors;
        while (p != nullptr) {
            ancestors.insert(p);
            p = parent[p];
        }

        // find the first common ancestor of p and q
        while (ancestors.find(q) == ancestors.end()) {
            q = parent[q];
        }

        return q;
    }

}
