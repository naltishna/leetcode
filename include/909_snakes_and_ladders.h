/*
https://leetcode.com/problems/snakes-and-ladders/description/

909. Snakes and Ladders

You are given an n x n integer matrix board where the cells are labeled from 1 to n^2 in a Boustrophedon style
starting from the bottom left of the board (i.e. label 1 is the bottom-left corner and label n^2 is the top-right corner).
Each move on the board consists of starting on a square and then using a 6-sided die to move at most 6 squares away.

The board contains snakes and ladders: if you land on a square with the start of a snake or ladder, you move to the
corresponding end. Snakes and ladders only move you forward or backward once per move; once you land on the destination,
you do not move again unless you roll again.

Return the least number of moves required to reach the n^2 square. If it is not possible, return -1.

Example 1:
Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],
[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4

Example 2:
Input: board = [[-1,-1],[-1,3]]
Output: 1

Constraints:
n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n^2].
The squares labeled 1 and n^2 do not have snakes or ladders.
*/

#pragma once

#include "class_version.h"
#include <vector>

namespace _909 {

    template <class V>
    class Solution {
    public:
        int snakesAndLadders(std::vector<std::vector<int>>& board);
    };

}
