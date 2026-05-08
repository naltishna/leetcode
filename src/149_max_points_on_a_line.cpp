#include "149_max_points_on_a_line.h"

#include "class_version.h"

#include <algorithm>
#include <cstddef>
#include <numeric>
#include <unordered_map>

namespace _149 {

    /*
    * Brute force approach.
    *
    * Enumerate all pairs of points as a line baseline,
    * count how many other points lie on that line via the cross-product (= zero -> collinear).
    *
    * Time complexity:
    * O(n^3)
    *
    * Space complexity:
    * O(1)
    */
    int Solution<ver1>::maxPoints(std::vector<std::vector<int>>& points) {
        const int n = static_cast<int>(points.size());
        if (n <= 2) {
            return n;
        }

        int maxCount = 2;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int count = 2;

                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) {
                        continue;
                    }

                    const long long cross = 1LL * (points[j][0] - points[i][0]) * (points[k][1] - points[i][1])
                        - 1LL * (points[j][1] - points[i][1]) * (points[k][0] - points[i][0]);

                    if (cross == 0) {
                        ++count;
                    }
                }

                maxCount = std::max(maxCount, count);
            }
        }

        return maxCount;
    }

    /*
    * For each point i, compute a normalized slope to every other point j
    * and count how many points share the same slope - those are collinear.
    *
    * Key implementation details:
    * Slope stored as reduced fraction (dx, dy) via gcd - avoids floating-point errors.
    * Direction normalized so dx >= 0 - eliminates duplicate slopes from opposite directions.
    * Vertical lines unified to dy = 1 - no division-by-zero
    * Fraction packed into a single long long key - fast unordered_map lookup.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(n)
    */
    int Solution<ver2>::maxPoints(std::vector<std::vector<int>>& points) {
        const int n = static_cast<int>(points.size());
        if (n <= 2) {
            return n;
        }

        int maxCount = 0;

        for (int i = 0; i < n; ++i) {
            int maxAlongOneSlope = 0;
            std::unordered_map<long long, int> slopeCnt;
            slopeCnt.reserve(static_cast<std::size_t>(n));

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    continue;
                }

                // Reduce the slope fraction using gcd (greatest common divisor).
                const int divisor = std::gcd(dx, dy);
                dx /= divisor;
                dy /= divisor;

                // Normalize direction sign.
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                else if (dx == 0) {
                    dy = 1; // Vertical line through the anchor point.
                }

                const long long slopeKey =
                    (static_cast<long long>(static_cast<unsigned int>(dx)) << 32)
                    | static_cast<unsigned int>(dy);
                maxAlongOneSlope = std::max(maxAlongOneSlope, ++slopeCnt[slopeKey]);
            }

            maxCount = std::max(maxCount, maxAlongOneSlope + 1);
        }

        return maxCount;
    }

}
