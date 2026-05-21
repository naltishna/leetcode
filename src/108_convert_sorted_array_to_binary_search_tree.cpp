#include "108_convert_sorted_array_to_binary_search_tree.h"

namespace _108 {

    /*
    * Recursive divide and conquer approach.
    *
    * Always picks the middle element as root, then recursively builds left and right subtrees.
    *
    * Time complexity:
    * O(n) - every element visited exactly once
    *
    * Space complexity:
    * O(log n) - recursion depth equals tree height
    */
    RawPointer::TreeNode* Solution::sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        return buildSubtree(nums, 0, static_cast<int>(nums.size()) - 1);
    }

    RawPointer::TreeNode* Solution::buildSubtree(const std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        const int mid = left + (right - left) / 2;
        auto* root = new RawPointer::TreeNode(nums[mid]);

        root->left = buildSubtree(nums, left, mid - 1);
        root->right = buildSubtree(nums, mid + 1, right);

        return root;
    }

}
