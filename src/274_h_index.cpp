#include "274_h_index.h"

#include <algorithm>

namespace _274 {

    /*
     * Sort the citations in descending order and find the maximum h such that there are at least h papers with at least h citations.
     *
     * Time complexity:
     * O(NlogN) due to sorting.
     *
     * Space complexity:
     * O(1) if we sort in place, otherwise O(N) for the sorted array.
     */
    int Solution::hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), std::greater<int>());

        int h = 0;
        while (h < citations.size() && citations[h] > h) {
            h++;
        }

        return h;
    }

}