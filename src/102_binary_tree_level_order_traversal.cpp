#include "102_binary_tree_level_order_traversal.h"

#include <queue>

namespace _102 {

    /*
    * Approach: BFS (Level-order Traversal).
    *
    * Processes the tree level by level using a queue. For each level,
    * collects all node values into a temporary array, then appends it to the result.
    *
    * Time complexity:
    * O(N) - every node visited once
    *
    * Space complexity:
    * O(N) - result stores all N values + queue holds at most one full level
    */
    std::vector<std::vector<int>> Solution::levelOrder(SmartPointer::TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        std::queue<SmartPointer::TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            const int levelSize = static_cast<int>(nodes.size());
            std::vector<int> temp;
            temp.reserve(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                SmartPointer::TreeNode* node = nodes.front();
                nodes.pop();

                temp.push_back(node->val);

                if (node->left) {
                    nodes.push(node->left.get());
                }

                if (node->right) {
                    nodes.push(node->right.get());
                }
            }

            res.push_back(std::move(temp));
        }

        return res;
    }

}
