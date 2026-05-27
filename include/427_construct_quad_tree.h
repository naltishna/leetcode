/*
https://leetcode.com/problems/construct-quad-tree/description/

427. Construct Quad Tree

Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children:
topLeft, topRight, bottomLeft and bottomRight. Each node in the quad tree has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
Notice that you can assign the value to a node when the node is both a leaf and a parent of four children.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown in the photo below.
Notice that 0 represents False and 1 represents True in the photo.

Example 2:
Input: grid = [[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]]
Output: [[1,1]]
Explanation: All values are the same, so we can construct a leaf node.

Example 3:
Input: grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
Output: [[0,1],[1,1],[1,0],[0,1],[1,0],[1,0],[1,1],[0,1],[1,0]]

Constraints:
n == grid.length == grid[i].length
n == 2^x where 0 <= x <= 6
*/

#pragma once

#include <vector>

namespace _427 {

    class Node {
    public:
        bool val;
        bool isLeaf;
        Node* topLeft;
        Node* topRight;
        Node* bottomLeft;
        Node* bottomRight;

        Node()
            : val(false),
              isLeaf(false),
              topLeft(nullptr),
              topRight(nullptr),
              bottomLeft(nullptr),
              bottomRight(nullptr) {
        }

        Node(bool val, bool isLeaf)
            : val(val),
              isLeaf(isLeaf),
              topLeft(nullptr),
              topRight(nullptr),
              bottomLeft(nullptr),
              bottomRight(nullptr) {
        }

        Node(bool val, bool isLeaf, Node* topLeft, Node* topRight, Node* bottomLeft, Node* bottomRight)
            : val(val),
              isLeaf(isLeaf),
              topLeft(topLeft),
              topRight(topRight),
              bottomLeft(bottomLeft),
              bottomRight(bottomRight) {
        }
    };

    class Solution {
    public:
        Node* construct(std::vector<std::vector<int>>& grid);
    };

}
