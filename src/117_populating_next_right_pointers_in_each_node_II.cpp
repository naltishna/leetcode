#include "117_populating_next_right_pointers_in_each_node_II.h"
#include "class_version.h"

#include <queue>

namespace _117 {

    /*
    * Level-by-level linking using existing next pointers on the current row.
    * A dummy head chains the children of the current level; then move to the next level.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    Node* Solution<ver1>::connect(Node* root) {
        Node* levelStart = root;

        while (levelStart != nullptr) {
            Node dummy(0);
            Node* tail = &dummy;

            // Link the children of the current level.
            for (Node* node = levelStart; node != nullptr; node = node->next) {
                if (node->left != nullptr) {
                    tail->next = node->left;
                    tail = tail->next;
                }

                if (node->right != nullptr) {
                    tail->next = node->right;
                    tail = tail->next;
                }
            }

            levelStart = dummy.next;
        }

        return root;
    }

    /*
    * Approach: BFS (Level-order Traversal).
    *
    * Processes the tree level by level using a queue. For each node in a level,
    * sets next to the front of the queue (the next node in the same level),
    * or nullptr if it's the last node in that level.
    *
    * Time complexity:
    * O(N) - every node visited once
    *
    * Space complexity:
    * O(W) - queue holds at most one full level, where W is max width
    */
    template <>
    Node* Solution<ver2>::connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        std::queue<Node*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            const int levelSize = static_cast<int>(nodes.size());

            for (int i = 0; i < levelSize; ++i) {
                Node* node = nodes.front();
                nodes.pop();

                node->next = (i + 1 < levelSize) ? nodes.front() : nullptr;

                if (node->left != nullptr) {
                    nodes.push(node->left);
                }

                if (node->right != nullptr) {
                    nodes.push(node->right);
                }
            }
        }

        return root;
    }

}
