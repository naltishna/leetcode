#pragma once

#include <memory>
#include <utility>

/**
 * Definition for a Balanced Binary Tree (BBT) and for a Binary Search Tree (BST).
 *
 * See tasks 110, 653.
 */

namespace RawPointer {

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

}

namespace SmartPointer {

    struct TreeNode {
        int val;
        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right)
            : val(x), left(std::move(left)), right(std::move(right)) {
        }
    };

}