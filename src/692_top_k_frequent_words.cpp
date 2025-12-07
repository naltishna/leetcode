#include "692_top_k_frequent_words.h"

#include <map>
#include <queue>

namespace _692 {

    /**
    * Utilizes a priority_queue for efficient retrieval of top elements.
    * Handles ties correctly via lexicographic comparison.
    * Performs well even for large datasets due to logarithmic operations (the map internally maintains a balanced binary search tree (Red-Black Tree).
    * 
    * - Time complexity:
    * O(k log m), where m - is unique words
    * 
    * - Space complexity:
    * O(m)
    */

    std::vector<std::string> Solution::topKFrequent(std::vector<std::string>& words, int k) {
        std::vector<std::string> result;
        if (words.empty() || words.size() < k) {
            return result;
        }

        std::map<std::string, int> word_count;
        for (auto& word : words) {
            word_count[word]++;
        }

        auto cmp = [](const auto& a, const auto& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
            };

        std::priority_queue<std::pair<std::string, int>,
                            std::vector<std::pair<std::string, int>>,
                            decltype(cmp)> pq(word_count.begin(), word_count.end());
        while (k-- > 0 && !pq.empty()) {
            auto& top = pq.top();
            result.push_back(top.first);
            pq.pop();
        }

        return result;
    }

}