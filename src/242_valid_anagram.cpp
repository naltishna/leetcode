#include "242_valid_anagram.h"
#include "class_version.h"

#include <algorithm>
#include <vector>

namespace _242 {

    /*
    * Compare sorted strings.
    *
    * Time complexity:
    * O(NLogN), where N is the length of the string
    *
    * Space complexity:
    * O(1)
    */
    bool Solution<v1>::isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }

    /*
    * Array of counters.
    *
    * NOTE: Applicable for ASCII/lowercase only.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    bool Solution<v2>::isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        // The English alphabet consists of 26 letters
        constexpr int TOTAL_LETTERS = 26;
        int count[TOTAL_LETTERS] = { 0 };

        for (size_t i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int c : count) {
            if (c != 0) return false;
        }

        return true;
    }

}