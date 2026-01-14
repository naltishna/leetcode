#include "12_integer_to_roman.h"
#include "class_version.h"

#include <vector>
#include <map>
#include <iterator>

namespace _12 {

    /*
    * 1. Hashing: A map (std::map) is used to quickly map numeric values ​​to the corresponding Roman letters.
    * 2. Iterative construction: The algorithm iterates through each digit of the number from left to right, calculating each digit and its position in the number.
    * 3. Special case handling: Special cases such as "IV", "IX", "XL", "XC", "CD", and "CM" are handled separately, using the differences between the values ​​in the map.
    *
    * Time complexity:
    * O(d), where d is the number of digits in the number.
    *
    * Space complexity:
    * O(1)
    */
    std::string Solution<v1>::intToRoman(int num) {
        std::map<int, char, std::greater<int>> int_to_roman{
            {1000, 'M'},
            {500, 'D'},
            {100, 'C'},
            {50, 'L'},
            {10, 'X'},
            {5, 'V'},
            {1, 'I'}
        };
        std::string output;

        for (auto it = int_to_roman.begin(); it != int_to_roman.end() && num > 0; ++it) {
            while (num > 0) {
                int digitsCount = floor(log10(abs(num))) + 1; // 3749 -> 4
                int rank = pow(10, digitsCount - 1);          // 3749 -> 1000
                int grade = num / rank;                       // 3749 -> 3
                int digit = rank * grade;                     // 3749 -> 3000

                // 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM)
                if ((grade == 9 || grade == 4) && (it->first - digit == rank)) {
                    output += int_to_roman[it->first - digit];
                    output += int_to_roman[it->first];
                    num -= digit;
                }
                else if (num - it->first >= 0) {
                    output += it->second;
                    num -= it->first;
                }
                else {
                    break;
                }
            }
        }

        return output;
    }

    /*
    * Use a greedy approach.
    *
    * Create a fixed list of numbers and their corresponding Roman symbols, sorted in descending order of numerical value.
    * To convert an Arabic numeral to a Roman numeral, we sequentially select the largest available numbers from the list until the original number becomes zero.
    *
    * Time complexity:
    * O(1)
    *
    * Space complexity:
    * O(1)
    */
    std::string Solution<v2>::intToRoman(int num) {
        static const std::pair<int, std::string> int_to_roman[] = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        std::string output;

        for (auto& pair : int_to_roman) {
            while (num >= pair.first) {
                output += pair.second;
                num -= pair.first;
            }
        }

        return output;
    }

}