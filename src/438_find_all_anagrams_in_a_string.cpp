#include "438_find_all_anagrams_in_a_string.h"

#include <array>

namespace _438 {

    /*
    * Sliding window and compare arrays.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    std::vector<int> Solution::findAnagrams(std::string s, std::string p) {
        std::vector<int> res = {};
        int s_size = s.size();
        int p_size = p.size();
        if (s_size < p_size) return res;

        // The English alphabet consists of 26 letters
        constexpr int TOTAL_LETTERS = 26;
        std::array<int, TOTAL_LETTERS> p_count = { 0 };
        std::array<int, TOTAL_LETTERS> s_count = { 0 };
        for (int i = 0; i < p_size; ++i) {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++; // 1st window init
        }

        // check 1st window
        if (p_count == s_count) {
            res.push_back(0);
        }
        
        for (int i = p_size; i < s_size; ++i) {
            s_count[s[i - p_size] - 'a']--;
            s_count[s[i] - 'a']++;

            if (p_count == s_count) {
                res.push_back(i - p_size + 1);
            }
        }

        return res;
    }

}