#include "200_number_of_islands.h"
#include "class_version.h"

#include <vector>
#include <queue>

namespace _200 {

    static constexpr std::pair<int, int> DIRECTIONS[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    /*
    * Use BFS (Breadth-First Search) approach.
    * BFS: (queue) — FIFO
    * 
    * Time complexity:
    * O(R*C), where R are rows, C are columns.
    * 
    * Space complexity:
    * O(R*C)
    */
    int Solution<v1>::numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        const size_t ROW_S = grid.size();
        const size_t COL_S = grid[0].size();

        int lands = 0;
        for (int row = 0; row < ROW_S; ++row) {
            for (int col = 0; col < COL_S; ++col) {
                if (grid[row][col] == '1') {
                    lands++;
                    bfs(grid, row, col);
                }
            }
        }
        return lands;
    }

    template<>
    void Solution<v1>::bfs(std::vector<std::vector<char>>& grid, int row, int col) {
        const size_t ROW_S = grid.size();
        const size_t COL_S = grid[0].size();

        std::queue<std::pair<int, int>> q;
        q.push({ row, col });
        grid[row][col] = '0';

        while (!q.empty()) {
            auto& [row_, col_] = q.front();
            q.pop();

            for (const auto& d : DIRECTIONS) {
                int new_row = row_ + d.first;
                int new_col = col_ + d.second;

                if (new_row >= 0 && new_row < ROW_S &&
                    new_col >= 0 && new_col < COL_S && 
                    grid[new_row][new_col] == '1') {
                    q.push({ new_row, new_col });
                    grid[new_row][new_col] = '0';
                }
            }
        }
    }

    /*
    * Use DFS (Depth-First Search) recursion approach.
    * DFS is simpler then BFS and uses less memory. In very large grids recursive DFS can lead to stack overflow.
    *
    * Time complexity:
    * O(R*C), where R are rows, C are columns.
    *
    * Space complexity:
    * O(R*C)
    */
    int Solution<v2>::numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        const size_t ROW_S = grid.size();
        const size_t COL_S = grid[0].size();

        int lands = 0;
        for (int row = 0; row < ROW_S; ++row) {
            for (int col = 0; col < COL_S; ++col) {
                if (grid[row][col] == '1') {
                    lands++;
                    dfs(grid, row, col);
                }
            }
        }
        return lands;
    }

    template<>
    void Solution<v2>::dfs(std::vector<std::vector<char>>& grid, int  row, int  col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        dfs(grid, row - 1, col);    // Up
        dfs(grid, row + 1, col);    // Down
        dfs(grid, row, col - 1);    // Left
        dfs(grid, row, col + 1);    // Right
    }

}