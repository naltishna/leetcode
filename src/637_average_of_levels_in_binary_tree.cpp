#include "637_average_of_levels_in_binary_tree.h"

#include <queue>

namespace _637 {

    /*
    * Approach: BFS (Level-order Traversal).
    *
    * Processes the tree level by level using a queue. For each node in a level,
    * calculates the average value of the nodes in that level, then divides by level size to get the average.
    *
    * Time complexity:
    * O(N) - every node visited once
    *
    * Space complexity:
    * O(W) - queue holds at most one full level, where W is max width
    */
    std::vector<double> Solution::averageOfLevels(SmartPointer::TreeNode* root) {
        std::vector<double> res;
        if (root == nullptr) {
            return res;
        }

        std::queue<SmartPointer::TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            const int levelSize = static_cast<int>(nodes.size());
            double sum = 0;

            for (int i = 0; i < levelSize; ++i) {
                SmartPointer::TreeNode* node = nodes.front();
                nodes.pop();

                sum += node->val;

                if (node->left) {
                    nodes.push(node->left.get());
                }

                if (node->right) {
                    nodes.push(node->right.get());
                }
            }

            res.push_back(sum / levelSize);
        }

        return res;
    }

}
