#include "909_snakes_and_ladders.h"
#include "class_version.h"

#include <queue>
#include <utility>
#include <vector>

namespace _909 {

    /*
    * Convert a square number to row and column coordinates.
    *
    * Example:
    * 4 | 3
    * 1 | 2
    * where n = 2, square = 3:
    * --square → square = 2
    * row = (2-1) - 2/2 = 0 (up)
    * col = 2 % 2 = 0
    * (n - row) % 2 = 2 % 2 = 0 → col = 1 - 0 = 1
    * (row, col) = (0, 1) → board[0][1] = 3 ✓
    *
    * "zigzag number" → (row, col) in board[][]:
    * - division by n gives the row below;
    * - %n is the position in the row;
    * - (n-row)%2 is whether to mirror the column for the zigzag.
    */
    static std::pair<int, int> squareToCoords(int square, int n) {
        // Square number is 1-based, so we need to convert it to 0-based.
        // 1-based — start from 1, finish in n^2, as on the board in the task; 
        // 0-based — start from 0, finish in n-1, like in a vector
        --square;

        const int row = (n - 1) - (square / n);
        int col = square % n;

        // If the row is even, the column needs to be reversed.
        if ((n - row) % 2 == 0) {
            col = (n - 1) - col;
        }

        return { row, col };
    }

    /*
    * Resolve the square number to the actual square number.
    */
    static int resolveSquare(int square, const std::vector<std::vector<int>>& board) {
        const int n = static_cast<int>(board.size());
        if (square == n * n) {
            return square;
        }

        const auto [row, col] = squareToCoords(square, n);
        // Get the destination square for the current square.
        const int port = board[row][col];

        // If the square is a snake or ladder, return the destination square,
        // otherwise return the original square.
        return port == -1 ? square : port;
    }

    /*
    * Approach: BFS on board squares.
    *
    * Models the board as a graph where each square is a node.
    * BFS finds the minimum number of dice rolls to reach n^2.
    * Each step tries all 6 dice values, resolves snakes/ladders,
    * and tracks visited squares via dist array.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(n^2)
    */
    template<>
    int Solution<ver1>::snakesAndLadders(std::vector<std::vector<int>>& board) {
        const int n = static_cast<int>(board.size());
        // The target square is the last square (n^2).
        const int target = n * n;
        // Distance to the target square is initialized to -1.
        std::vector<int> dist(target + 1, -1);
        std::queue<int> q;

        // Start from square 1.
        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            const int square = q.front();
            q.pop();

            if (square == target) {
                return dist[square];
            }

            // Try all possible dice rolls (1..6).
            for (int dice = 1; dice <= 6; ++dice) {
                int next = square + dice;
                if (next > target) {
                    break;
                }

                // Resolve the square number to the actual square number.
                next = resolveSquare(next, board);

                if (dist[next] != -1) {
                    continue;
                }

                // Update the distance to the next square.
                dist[next] = dist[square] + 1;
                q.push(next);
            }
        }

        return -1;
    }

    /*
    * Approach: BFS with precomputed snake/ladder destinations.
    *
    * Same as ver1, but destination for each square is computed once before the search.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(n^2)
    */
    template<>
    int Solution<ver2>::snakesAndLadders(std::vector<std::vector<int>>& board) {
        const int n = static_cast<int>(board.size());
        const int target = n * n;

        // Precompute the destination for each square.
        std::vector<int> destination(target + 1);
        for (int square = 1; square < target; ++square) {
            destination[square] = resolveSquare(square, board);
        }
        destination[target] = target;

        std::vector<int> dist(target + 1, -1);
        std::queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            const int square = q.front();
            q.pop();

            if (square == target) {
                return dist[square];
            }

            // Try all possible dice rolls (1..6).
            for (int dice = 1; dice <= 6; ++dice) {
                int nextSquare = square + dice;
                if (nextSquare > target) {
                    break;
                }

                nextSquare = destination[nextSquare];

                if (dist[nextSquare] != -1) {
                    continue;
                }

                // Update the distance to the next square.
                dist[nextSquare] = dist[square] + 1;
                q.push(nextSquare);
            }
        }

        return -1;
    }

}
