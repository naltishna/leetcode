#include "392_is_subsequence.h"
#include "class_version.h"

#include <algorithm>

namespace _392 {

    /*
    * Use two pointers.
    *
    * Time complexity:
    * O(n+m), where m is the length of string s, and n is the length of string t
    *
    * Space complexity:
    * O(1)
    */
    bool Solution<v1>::isSubsequence(std::string s, std::string t) {
        if (s.size() > t.size()) return false;

        int i = 0;
        for (int j = 0; j < t.size() && i < s.size(); ++j) {
            if (s[i] == t[j]) {
                i++;
            }
        }

        return i == s.size();
    }

    /*
    * Use two pointers.
    *
    * Time complexity:
    * O(n+m), where m is the length of string s, and n is the length of string t
    *
    * Space complexity:
    * O(1)
    */
    bool Solution<v2>::isSubsequence(std::string s, std::string t) {
        if (s.size() > t.size()) return false;

        std::string_view sv = s, tv = t;
        auto it = sv.begin();

        for (auto ch : tv) {
            if (it != sv.end() && *it == ch) {
                ++it;
            }
        }

        return it == sv.end();
    }

}