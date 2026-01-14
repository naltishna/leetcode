/*
https://leetcode.com/problems/valid-anagram/description/

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.
*/

#pragma once

#include <string>

namespace _242 {

    template<class V>
    class Solution {
    public:
        bool isAnagram(std::string s, std::string t);
    };

}