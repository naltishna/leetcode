#include "100_same_tree.h"
#include "class_version.h"

#include <queue>
#include <utility>

namespace _100 {

    /*
    * Recursive DFS (depth-first traversal).
    *
    * Compare nodes top-down: if both null -> equal, one null -> not equal,
    * values differ -> not equal, else recurse on both subtrees.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h), call stack depth equals tree height
    */
    template <>
    bool Solution<ver1>::isSameTree(SmartPointer::TreeNode* p, SmartPointer::TreeNode* q) {
        if (p == q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        return p->val == q->val
            && Solution<ver1>::isSameTree(p->left.get(), q->left.get())
            && Solution<ver1>::isSameTree(p->right.get(), q->right.get());
    }

    /*
    * Iterative BFS (breadth-first traversal) with a queue.
    *
    * Queue pairs (p-node, q-node); enqueue matching children left-left and right-right.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(w), worst case O(n) for queue width
    */
    template <>
    bool Solution<ver2>::isSameTree(SmartPointer::TreeNode* p, SmartPointer::TreeNode* q) {
        std::queue<std::pair<SmartPointer::TreeNode*, SmartPointer::TreeNode*>> nodes;
        nodes.emplace(p, q);

        while (!nodes.empty()) {
            auto [pNode, qNode] = nodes.front();
            nodes.pop();

            if (pNode == qNode) {
                continue;
            }

            if (!pNode || !qNode || pNode->val != qNode->val) {
                return false;
            }

            nodes.emplace(pNode->left.get(), qNode->left.get());
            nodes.emplace(pNode->right.get(), qNode->right.get());
        }

        return true;
    }

}
