#include "289_game_of_life.h"
#include "class_version.h"

namespace {

    struct Cell {
        int row, col, cell;
    };

} // namespace

namespace _289 {

    /*
    * Deferred updates — scan the board in read-only mode, record every cell that must flip in a side buffer,
    * then apply all writes after the full scan (simulates simultaneous rules).
    * Neighbors via fixed 8-direction offsets.
    *
    * Time complexity:
    * O(m*n)
    *
    * Space complexity:
    * O(m*n)
    */
    template<>
    void Solution<ver1>::gameOfLife(std::vector<std::vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;

        static constexpr std::pair<int, int> directions[] = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };

        const size_t rows = board.size();
        const size_t cols = board[0].size();
        std::vector<Cell> changed;

        auto consider_cell = [&](int row, int col) {
            int live_neighbors = 0;
            int live_around_dead = 0;

            for (const auto& d : directions) {
                const int newRow = row + d.first;
                const int newCol = col + d.second;
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;

                if (board[row][col] == 1 && board[newRow][newCol] == 1) ++live_neighbors;
                if (board[row][col] == 0 && board[newRow][newCol] == 1) ++live_around_dead;
            }

            if (board[row][col] == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                changed.push_back({ row, col, 0 });
            }

            if (board[row][col] == 0 && live_around_dead == 3) {
                changed.push_back({ row, col, 1 });
            }
            };

        for (size_t row = 0; row < rows; ++row) {
            for (size_t col = 0; col < cols; ++col) {
                consider_cell(static_cast<int>(row), static_cast<int>(col));
            }
        }

        for (const auto& cell : changed) {
            board[cell.row][cell.col] = cell.cell;
        }
    }

    /*
    * Uses extra cell states to encode transitions without a copy:
    * 1 -> live
    * 2 -> was live, now dead (live -> dead)
    * 3 -> was dead, now live (dead -> live)
    * 
    * In the first pass, live_neighbors counts cells with value 1 or 2 (originally alive).
    * States are updated in-place. Second pass normalizes: 2 -> 0, 3 -> 1.
    * 
    * Time complexity:
    * O(m × n) — two full board scans
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    void Solution<ver2>::gameOfLife(std::vector<std::vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;

        static constexpr std::pair<int, int> directions[] =
        { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        auto live_neighbors = [&](int row, int col) {
            int n = 0;

            for (const auto& d : directions) {
                const int newRow = row + d.first;
                const int newCol = col + d.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    const int cell = board[newRow][newCol];
                    if (cell == 1 || cell == 2) {
                        ++n;
                    }
                }
            }

            return n;
        };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                const int neighbors = live_neighbors(row, col);

                if (board[row][col] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        board[row][col] = 2;
                    }
                }
                else if (neighbors == 3) {
                    board[row][col] = 3;
                }
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 2) {
                    board[row][col] = 0;
                }
                else if (board[row][col] == 3) {
                    board[row][col] = 1;
                }
            }
        }
    }

}