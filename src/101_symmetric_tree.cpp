#include "101_symmetric_tree.h"

#include <queue>

namespace _101 {

    /*
    * An iterative approach using the BFS (Breadth-First Search) method.
    *
    * Uses a queue to process tree nodes from top to bottom.
    * Checks tree symmetry by comparing corresponding nodes on the left and right at each level.
    * Provides an efficient solution by visiting each node only once.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    template<>
    bool Solution<_101_v1>::isSymmetric(SmartPointer::TreeNode* root) {
        std::queue<SmartPointer::TreeNode*> q;

        q.push(root->left.get());
        q.push(root->right.get());

        while (!q.empty()) {
            SmartPointer::TreeNode* leftNode = q.front();
            q.pop();
            SmartPointer::TreeNode* rightNode = q.front();
            q.pop();

            if (leftNode == rightNode) {
                continue;
            }

            if (!leftNode || !rightNode || leftNode->val != rightNode->val) {
                return false;
            }

            q.push(leftNode->left.get());
            q.push(rightNode->right.get());
            q.push(leftNode->right.get());
            q.push(rightNode->left.get());
        }

        return true;
    }

    /*
    * Recursive approach.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    template<>
    bool Solution<_101_v2>::isSymmetric(SmartPointer::TreeNode* root) {
        return checkSymmetric(root->left.get(), root->right.get());
    }

    template<>
    bool Solution<_101_v2>::checkSymmetric(SmartPointer::TreeNode* left, SmartPointer::TreeNode* right) {
        if (left == right) { // both are nullptr
            return true;
        }

        if (!left || !right) { // one is nullptr
            return false;
        }

        return left->val == right->val
            && Solution<_101_v2>::checkSymmetric(left->left.get(), right->right.get())
            && Solution<_101_v2>::checkSymmetric(left->right.get(), right->left.get());
    }

}