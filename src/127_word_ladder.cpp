#include "127_word_ladder.h"
#include "class_version.h"

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

namespace _127 {

    static bool differsByOne(const std::string& left, const std::string& right) {
        int diff = 0;

        for (size_t i = 0; i < left.size(); ++i) {
            if (left[i] != right[i]) {
                ++diff;
            }

            if (diff > 1) {
                return false;
            }
        }

        return diff == 1;
    }

    /*
    * Approach: BFS over wordList.
    *
    * From the current word, try every unused dictionary word that differs by exactly one letter.
    *
    * Time complexity:
    * O(N * L * W), where N is queue size, L is word length, W is wordList size
    *
    * Space complexity:
    * O(W)
    */
    template<>
    int Solution<ver1>::ladderLength(const std::string& beginWord,
                                     const std::string& endWord,
                                     const std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.contains(endWord)) {
            return 0;
        }

        std::vector<bool> used(wordList.size(), false);
        std::queue<std::pair<std::string, int>> q;
        q.push({ beginWord, 1 });

        while (!q.empty()) {
            const auto [word, steps] = q.front();
            q.pop();

            for (size_t i = 0; i < wordList.size(); ++i) {
                if (used[i]) {
                    continue;
                }

                if (!differsByOne(word, wordList[i])) {
                    continue;
                }

                used[i] = true;
                const int nextSteps = steps + 1;

                if (wordList[i] == endWord) {
                    return nextSteps;
                }

                q.push({ wordList[i], nextSteps });
            }
        }

        return 0;
    }

    /*
    * Approach: BFS with generated neighbors.
    *
    * For each word, try changing one letter to a-z and continue only if the result is still in the dictionary.
    * Remove a word from the set when it is visited so it is not used again.
    *
    * Time complexity:
    * O(N * L * 26)
    *
    * Space complexity:
    * O(W)
    */
    template<>
    int Solution<ver2>::ladderLength(const std::string& beginWord,
                                     const std::string& endWord,
                                     const std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.contains(endWord)) {
            return 0;
        }

        wordSet.erase(beginWord);

        std::queue<std::pair<std::string, int>> q;
        q.push({ beginWord, 1 });

        while (!q.empty()) {
            const auto [word, steps] = q.front();
            q.pop();

            for (size_t i = 0; i < word.size(); ++i) {
                std::string next = word;

                for (char letter = 'a'; letter <= 'z'; ++letter) {
                    if (letter == word[i]) {
                        continue;
                    }

                    next[i] = letter;

                    if (!wordSet.contains(next)) {
                        continue;
                    }

                    if (next == endWord) {
                        return steps + 1;
                    }

                    wordSet.erase(next);
                    q.push({ next, steps + 1 });
                }
            }
        }

        return 0;
    }

}
