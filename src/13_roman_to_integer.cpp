#include "13_roman_to_integer.h"

#include <unordered_map>

namespace _13 {

    /*
    * Iterating through the string of characters from left to right:
    * - If the value of the current character is less than the value of the next character, the current value is subtracted from the total result (e.g., IV = 4).
    * - If the current value is greater than or equal to the next, the current value is added to the result (e.g., VI = 6).
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    int Solution::romanToInt(std::string s) {
        std::unordered_map<char, int> map {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;

        for (size_t i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && map[s[i]] < map[s[i + 1]]) {
                result -= map[s[i]];
            }
            else {
                result += map[s[i]];
            }
        }

        return result;
    }

}