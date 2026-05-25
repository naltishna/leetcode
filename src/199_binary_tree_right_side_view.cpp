#include "199_binary_tree_right_side_view.h"

#include <queue>

namespace _199 {

    /*
    * Approach: BFS (Level-order Traversal).
    *
    * Processes the tree level by level using a queue. For each level, records only the last
    * node's value (i == levelSize - 1), which represents what's visible from the right side.
    *
    * Time complexity:
    * O(N) - every node visited once
    *
    * Space complexity:
    * O(W) - queue holds at most one full level, where W is max width
    */
    std::vector<int> Solution::rightSideView(SmartPointer::TreeNode* root) {
        std::vector<int> res;
        if (root == nullptr) {
            return res;
        }

        std::queue<SmartPointer::TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            const int levelSize = static_cast<int>(nodes.size());

            for (int i = 0; i < levelSize; ++i) {
                SmartPointer::TreeNode* node = nodes.front();
                nodes.pop();

                if (i == levelSize - 1) {
                    res.push_back(node->val);
                }

                if (node->left) {
                    nodes.push(node->left.get());
                }

                if (node->right) {
                    nodes.push(node->right.get());
                }
            }
        }

        return res;
    }

}
