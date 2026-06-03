#include "354_russian_doll_envelopes.h"
#include "class_version.h"

#include <algorithm>
#include <vector>

namespace _354 {

    /*
    * Sort the envelopes by width, then by height.
    * If the width is equal, sort by height in descending order.
    * If the width is not equal, sort by width in ascending order.
    */
    static void sortEnvelopes(std::vector<std::vector<int>>& envelopes, bool descendingHeightForEqualWidth) {
        std::sort(envelopes.begin(), envelopes.end(),
            [descendingHeightForEqualWidth](const std::vector<int>& a, const std::vector<int>& b) {
                if (a[0] != b[0]) {
                    return a[0] < b[0];
                }

                return descendingHeightForEqualWidth ? a[1] > b[1] : a[1] < b[1];
            });
    }

    /*
    * Approach: sort by width, then DP LIS on heights.
    *
    * After sorting by width ascending, find the longest chain where both width and height strictly increase.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(n)
    */
    template<>
    int Solution<ver1>::maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }


        sortEnvelopes(envelopes, false);

        const int n = static_cast<int>(envelopes.size());
        std::vector<int> dp(n, 1);
        int best = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }

            best = std::max(best, dp[i]);
        }

        return best;
    }

    /*
    * Approach: sort by width ascending and height descending for equal widths, then LIS on heights
    * with binary search.
    *
    * The height subsequence length equals the maximum nesting depth.
    *
    * Time complexity:
    * O(n log n), n is the number of envelopes
    *
    * Space complexity:
    * O(n)
    */
    template<>
    int Solution<ver2>::maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }

        // Sort the envelopes by width ascending and height descending for equal widths.
        sortEnvelopes(envelopes, true);

        std::vector<int> tails;

        for (const auto& envelope : envelopes) {
            const int height = envelope[1];
            auto it = std::lower_bound(tails.begin(), tails.end(), height);

            if (it == tails.end()) {
                tails.push_back(height);
            }
            else {
                *it = height; // Replace the height with the new height.
            }
        }

        return tails.size();
    }

}
