/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]

Explanation: [0,-3,10,null,5,9] will also be accepted.

Example 2:
Input: nums = [1,3]
Output: [1,null,3]

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/

#pragma once

#include "tree_node.h"

#include <vector>

namespace _108 {

    class Solution {
    public:
        RawPointer::TreeNode* sortedArrayToBST(std::vector<int>& nums);

    private:
        RawPointer::TreeNode* buildSubtree(const std::vector<int>& nums, int left, int right);
    };

}
