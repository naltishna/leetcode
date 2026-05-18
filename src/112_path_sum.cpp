#include "112_path_sum.h"

namespace _112 {

    /*
    * Recursive DFS (Depth-First Search) approach.
    *
    * The solution traverses the tree recursively, subtracting each node's value from the target as it goes deeper.
    *
    * Logic:
    * Base case 1: empty node -> false.
    * Base case 2: leaf node -> check if remaining sum equals the node's value.
    * Recursive case: subtract current value, recurse into left and right subtrees.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(h)
    */
    bool Solution::hasPathSum(SmartPointer::TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        const int remainder = targetSum - root->val;
        return hasPathSum(root->left.get(), remainder)
            || hasPathSum(root->right.get(), remainder);
    }

}