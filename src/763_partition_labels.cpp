#include "763_partition_labels.h"

#include <unordered_map>

namespace _763 {

    /*
    * The algorithm uses a greedy strategy.
    *
    * Complexity
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    std::vector<int> Solution::partitionLabels(std::string s) {
        std::unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i]] = i;
        }

        std::vector<int> result;
        // start, end partition positions
        int start = 0, end = 0;

        for (int i = 0; i < s.length(); ++i) {
            end = std::max(end, last_occurrence[s[i]]);
            if (end == i) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }

}