#include "58_length_of_last_word.h"

#include <vector>
#include <sstream>

namespace _58 {
    /*
    * Use stream processing of a string (std::istringstream class).
    * 
    * ">>" automatically skips any extra whitespace characters (spaces, tabs, newline and so on).
    * 
    * Time complexity:
    * O(n)
    * 
    * Space complexity:
    * O(1)
    */
    int Solution::lengthOfLastWord(std::string s) {
        std::istringstream iss(s);
        std::string word, lastWord;

        while (iss >> word) {
            lastWord = word;
        }

        return lastWord.length();
    }

}