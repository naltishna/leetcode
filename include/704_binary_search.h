/*
* https://leetcode.com/problems/binary-search/
*
704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1

Explanation: 2 does not exist in nums so return -1

Constraints:

1 <= nums.length <= 10^4
-10^4 < nums[i], target < 10^4
All the integers in nums are unique.
nums is sorted in ascending order.
*/

#ifndef _704_HEADER_FILE_h
#define _704_HEADER_FILE_h

#include <vector>

namespace _704_recursion {

    //Recursion
    class Solution {
    public:
        int search(const std::vector<int>& nums, int target);
    private:
        int recursiveSearch(const std::vector<int>& nums, int target, int lowInd, int highInd);
    };

}

namespace _704_STL {

    //STL
    class Solution {
    public:
        int search(const std::vector<int>& nums, int target);
    };

}

namespace _704_binary_search {

    //binary_search
    class Solution {
    public:
        // const added to make possible using of {} in my_assert(-1 == s.search({}, 5));
        int search(const std::vector<int>& nums, int target);
    };

}

namespace _704_linear_search {

    // linear_search
    class Solution {
    public:
        int search(const std::vector<int>& nums, int target);
    };

}

#endif