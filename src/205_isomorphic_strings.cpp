#include "205_isomorphic_strings.h"
#include "class_version.h"

#include <unordered_map>
#include <unordered_set>
#include <iostream>

namespace _205 {

    /*
    * Using index mapping to verify one-to-one character relationships between two strings.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    bool Solution<v1>::isIsomorphic(std::string s, std::string t) {
        if (s.size() != t.size()) 
            return false;

        int m1[256] = {};
        int m2[256] = {};

        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) 
                return false;

            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }

        return true;
    }

    /*
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    template<>
    bool Solution<v2>::isIsomorphic(std::string s, std::string t) {
        if (s.size() != t.size()) 
            return false;

        std::unordered_map<char, char> s_to_t;
        std::unordered_map<char, char> t_to_s;

        for (int i = 0; i < s.size(); ++i) {
            char char_s = s[i];
            char char_t = t[i];

            if (s_to_t.count(char_s)) {
                if (s_to_t[char_s] != char_t) {
                    return false;
                }

            }

            if (t_to_s.count(char_t)) {
                if (t_to_s[char_t] != char_s) {
                    return false;
                }
            }

            s_to_t[char_s] = char_t;
            t_to_s[char_t] = char_s;
        }

        return true;
    }

    /*
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    template<>
    bool Solution<v3>::isIsomorphic(std::string s, std::string t) {
        if (s.size() != t.size())
            return false;

        std::unordered_map<char, char> charsMapping;
        std::unordered_set<char> usedChars;

        for (int i = 0; i < s.length(); ++i) {
            char charS = s.at(i);
            char charT = t.at(i);

            auto it_t_to_s = charsMapping.find(charS);
            if (it_t_to_s != charsMapping.end()) {
                if (charsMapping[charS] != charT) {
                    return false;
                }
            }
            else {
                auto it_t_to_s = usedChars.find(charT);
                if (it_t_to_s != usedChars.end()) {
                    return false;
                }
                charsMapping[charS] = charT;
                usedChars.insert(charT);
            }
        }
        return true;
    }

}