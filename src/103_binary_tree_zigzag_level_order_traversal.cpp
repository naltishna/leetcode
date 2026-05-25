#include "103_binary_tree_zigzag_level_order_traversal.h"

#include <algorithm>
#include <queue>

namespace _103 {

    /*
    * Approach: BFS (Level-order Traversal) with alternating direction.
    *
    * Processes the tree level by level using a queue, but alternates direction each level via
    * a leftToRight flag. Odd levels are stored as-is, even levels are reversed before appending to result.
    *
    * Time complexity:
    * O(N) - every node visited once + O(W) reverse per level, overall O(N)
    *
    * Space complexity:
    * O(N) - result stores all N values + queue holds at most one full level
    */
    std::vector<std::vector<int>> Solution::zigzagLevelOrder(SmartPointer::TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        std::queue<SmartPointer::TreeNode*> nodes;
        nodes.push(root);
        bool leftToRight = true;

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

            if (!leftToRight) {
                std::reverse(temp.begin(), temp.end());
            }

            leftToRight = !leftToRight;
            res.push_back(std::move(temp));
        }

        return res;
    }

}
