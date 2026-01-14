#include "653_two_sum_IV_input_is_a_BST.h"

#include <stack>
#include <unordered_set>
#include <queue>

namespace _653 {

    /*
    * Breadth-First Search (BFS) and HashSet — O(n) time, O(n) memory.
    * BFS guarantees that each node is processed efficiently without visiting it multiple times.
    * Best for general use — works for any binary tree.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    bool Solution<_653_BFS_ver>::findTarget(SmartPointer::TreeNode* root, int k) {
        std::unordered_set<int> keep;
        std::queue<SmartPointer::TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            SmartPointer::TreeNode* node = q.front();
            q.pop();

            if (keep.count(k - node->val)) {
                return true;
            }

            keep.insert(node->val);

            if (node->left) q.push(node->left.get());
            if (node->right) q.push(node->right.get());
        }

        return false;
    }

    /*
    * The most memory-optimal solution for BST.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    bool Solution<_653_memory_optimal_ver>::findTarget(SmartPointer::TreeNode* root, int k) {
        if (!root) {
            return false;
        }

        std::stack<SmartPointer::TreeNode*> leftStack, rightStack;
        SmartPointer::TreeNode* left = root, * right = root;

        while (left) {
            leftStack.push(left);
            left = left->left.get();
        }

        while (right) {
            rightStack.push(right);
            right = right->right.get();
        }

        left = leftStack.top();
        right = rightStack.top();

        while (left != right) {
            int sum = left->val + right->val;

            if (k == sum) {
                return true;
            }

            if (k > sum) {
                leftStack.pop();
                SmartPointer::TreeNode* node = left->right.get();
                while (node) {
                    leftStack.push(node);
                    node = node->left.get();
                }

                if (!leftStack.empty()) {
                    left = leftStack.top();
                }
            }
            else {
                rightStack.pop();
                SmartPointer::TreeNode* node = right->left.get();
                while (node) {
                    rightStack.push(node);
                    node = node->right.get();
                }
                if (!rightStack.empty()) {
                    right = rightStack.top();
                }
            }
        }

        return false;
    }

}

namespace _653_two_ptr {

    /*
    * Two pointers with in-order traversal (for BST) — O(n) time, O(n) memory.
    * Best for BST — uses the sorted property.
    */
    bool Solution::findTarget(SmartPointer::TreeNode* root, int k) {
        std::vector<int> sorted;
        inorder(root, sorted);

        int left = 0, right = sorted.size() - 1;

        while (left < right) {
            int sum = sorted[left] + sorted[right];
            if (sum == k) {
                return true;
            }
            if (sum < k) {
                left++;
            }
            else {
                right--;
            }
        }

        return false;
    }

    void Solution::inorder(SmartPointer::TreeNode* node, std::vector<int>& sorted) {
        if (!node) {
            return;
        }

        inorder(node->left.get(), sorted);
        sorted.push_back(node->val);
        inorder(node->right.get(), sorted);
    }

}