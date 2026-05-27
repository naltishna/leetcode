#include "427_construct_quad_tree.h"

#include <vector>

namespace _427 {

    namespace {

        // Checks if a 2x2 block is uniform.
        bool isUniform(const std::vector<std::vector<int>>& grid, int row, int col, int size) {
            const int value = grid[row][col];

            for (int i = row; i < row + size; ++i) {
                for (int j = col; j < col + size; ++j) {
                    if (grid[i][j] != value) {
                        return false;
                    }
                }
            }

            return true;
        }

        // Recursively destroys the quad tree.
        void destroyQuadTree(Node* root) {
            if (root == nullptr) {
                return;
            }

            std::vector<Node*> stack;
            std::vector<Node*> toDelete;
            stack.push_back(root);

            while (!stack.empty()) {
                Node* node = stack.back();
                stack.pop_back();

                if (node == nullptr) {
                    continue;
                }

                toDelete.push_back(node);

                if (!node->isLeaf) {
                    stack.push_back(node->topLeft);
                    stack.push_back(node->topRight);
                    stack.push_back(node->bottomLeft);
                    stack.push_back(node->bottomRight);
                }
            }

            for (Node* node : toDelete) {
                delete node;
            }
        }

    }

    /*
    * Approach: Bottom-up iterative merge.
    *
    * Every cell is a leaf node. Iteratively merge 2x2 blocks bottom-up (step = 2, 4, 8... n).
    * At each merge, check if the region is uniform, if so, collapse all 4 children into a single leaf,
    * otherwise create an internal node.
    *
    * Time complexity:
    * O(N� log N) - log N levels, each level scans the full NxN grid via isUniform
    *
    * Space complexity:
    * O(N�) - nodes array + quad tree size
    */
    Node* Solution::construct(std::vector<std::vector<int>>& grid) {
        const int n = static_cast<int>(grid.size());
        if (n == 0) {
            return nullptr;
        }

        std::vector<std::vector<Node*>> nodes(n, std::vector<Node*>(n, nullptr));

        // Build leaf nodes for each cell.
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                nodes[row][col] = new Node(grid[row][col] == 1, true);
            }
        }

        // Iteratively merge 2x2 blocks into larger quadrants, step = 2, 4, 8... n.
        for (int step = 2; step <= n; step *= 2) {
            const int half = step / 2;

            for (int row = 0; row < n; row += step) {
                for (int col = 0; col < n; col += step) {
                    Node* topLeft = nodes[row][col];
                    Node* topRight = nodes[row][col + half];
                    Node* bottomLeft = nodes[row + half][col];
                    Node* bottomRight = nodes[row + half][col + half];

                    if (isUniform(grid, row, col, step)) {
                        destroyQuadTree(topLeft);
                        destroyQuadTree(topRight);
                        destroyQuadTree(bottomLeft);
                        destroyQuadTree(bottomRight);

                        // Create a new leaf node for the merged region.
                        nodes[row][col] = new Node(grid[row][col] == 1, true);
                    }
                    else {
                        // Keep all four sub-quadrants as children of an internal node.
                        nodes[row][col] = new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
                    }
                }
            }
        }

        // Return the root of the quad tree.
        return nodes[0][0];
    }

}
