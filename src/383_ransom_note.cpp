#include "383_ransom_note.h"
#include "class_version.h"

#include <array>
#include <algorithm>
#include <unordered_map>

namespace _383 {

    static bool onlyLowerAlpha(const std::string& s) {
        return !s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c) {
            return c >= 'a' && c <= 'z';
            });
    }
    
    /*
    * Time complexity:
    * O(r+m)
    * 
    * Space complexity:
    * O(m)
    */
    template<>
    bool Solution<v1>::canConstruct(std::string ransomNote, std::string magazine) {
        if (ransomNote.size() > magazine.size()
            && onlyLowerAlpha(ransomNote) && onlyLowerAlpha(magazine)) {
            return false;
        }

        std::unordered_map<char, int> res;

        for (auto m : magazine) {
            res[m]++;
        }

        for (auto r : ransomNote) {
            if (res[r] <= 0) {
                return false;
            }
            res[r]--;
        }

        return true;
    }

    /*
    * Using a fixed-size frequency array to count character occurrences for efficient comparison.
    * 
    * Time complexity:
    * O(N+M)
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    bool Solution<v2>::canConstruct(std::string ransomNote, std::string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        std::array<int, 26> freq{}; // int freq[26] = {};

        for (char c : magazine) {
            freq[c - 'a']++;
        }

        for (auto ch : ransomNote) {
            if (freq[ch - 'a']-- <= 0) {
                return false;
            }
        }

        return true;
    }
}