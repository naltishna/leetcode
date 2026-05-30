/*
https://leetcode.com/problems/surrounded-regions/description/

130. Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded.

Connect: A cell is connected to adjacent cells horizontally or vertically.

Region: To form a connected region, all cells of one group are connected.

Surrounded: A region is surrounded if none of its cells is on the border of the board.

To capture a surrounded region, flip all 'O's into 'X's in that region. Return the board after capturing.

Example 1:
Input: board = [
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","X","O","X"],
  ["X","O","X","X"]
]
Output: [
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","O","X","X"]
]

Example 2:
Input: board = [["X"]]
Output: [["X"]]

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

#pragma once

#include <vector>

namespace _130 {

    class Solution {
    public:
        void solve(std::vector<std::vector<char>>& board);
    };

}
