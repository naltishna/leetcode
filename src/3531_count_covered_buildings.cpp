#include "3531_count_covered_buildings.h"
#include "class_version.h"

#include <unordered_map>
#include <map>
#include <set>

namespace _3531 {

    /*
    * Time complexity:
    * O(N x logN)
    * 
    * Space complexity:
    * O(N)
    */
    template<>
    int Solution<ver1>::countCoveredBuildings(int n, const std::vector<std::vector<int>>& buildings) {
        if (buildings.size() <= 4) {
            return 0;
        }

        std::map<int, std::set<int>> rowIndexes;
        std::map<int, std::set<int>> columnIndexes;

        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            rowIndexes[x].insert(y);
            columnIndexes[y].insert(x);
        }

        int count = 0;
        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            // Horizontal check (row x)
            const std::set<int>& rows = rowIndexes[x];
            // Is there a building on the left? (find an element strictly less than y)
            bool hasLeft = rows.lower_bound(y) != rows.begin();
            // Is there a building on the right? (find an element strictly greater than y)
            bool hasRight = rows.upper_bound(y) != rows.end();

            // If there are no neighbors to the left or right, we move on to the next building
            if (!hasLeft || !hasRight) {
                continue;
            }

            // Vertical check (column y)
            const std::set<int>& columns = columnIndexes[y];
            bool hasBelow = columns.lower_bound(x) != columns.begin();
            bool hasAbove = columns.upper_bound(x) != columns.end();

            // If there are neighbors on all four sides, increase the counter
            if (hasBelow && hasAbove) {
                count++;
            }
        }

        return count;
    }


    /*
    * For each building, check if it's strictly between the leftmost/rightmost building in its row and strictly between the topmost/bottommost building in its column.
    * Use two hash maps to store per-row and per-column min/max bounds in a single pass, then count matches in a second pass.
    * 
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    template<>
    int Solution<ver2>::countCoveredBuildings(int n, const std::vector<std::vector<int>>& buildings) {
        if (buildings.size() <= 4) {
            return 0;
        }

        std::unordered_map<int, std::pair<int, int>> rowBounds;
        std::unordered_map<int, std::pair<int, int>> colBounds;

        for (const auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            if (!rowBounds.count(x)) {
                rowBounds[x] = { y, y };
            }
            else {
                rowBounds[x].first = std::min(rowBounds[x].first, y);
                rowBounds[x].second = std::max(rowBounds[x].second, y);
            }

            if (!colBounds.count(y)) {
                colBounds[y] = { x, x };
            }
            else {
                colBounds[y].first = std::min(colBounds[y].first, x);
                colBounds[y].second = std::max(colBounds[y].second, x);
            }
        }

        int count = 0;

        for (const auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            bool hasHor = (y > rowBounds[x].first && y < rowBounds[x].second);
            bool hasVer = (x > colBounds[y].first && x < colBounds[y].second);

            if (hasHor && hasVer) {
                count++;
            }
        }

        return count;
    }

}