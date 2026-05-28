#include "17_letter_combinations_of_a_phone_number.h"
#include "class_version.h"

#include <functional>
#include <string>
#include <vector>

namespace _17 {

    /*
    * Approach: Backtracking.
    *
    * Builds each combination digit by digit using the phone keypad mapping.
    *
    * Time complexity:
    * O(4^n * n), where n is digits.length
    *
    * Space complexity:
    * O(n) - recursion depth and current combination
    */
    template<>
    std::vector<std::string> Solution<ver1>::letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }

        static const std::vector<std::string> phone{
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        std::vector<std::string> result;
        std::string current;

        std::function<void(int)> backtrack = [&](int index) {
            if (index == static_cast<int>(digits.size())) {
                result.push_back(current);
                return;
            }

            for (char letter : phone[digits[index] - '0']) {
                current.push_back(letter);
                backtrack(index + 1);
                current.pop_back();
            }
            };

        backtrack(0);

        return result;
    }

    /*
    * Approach: Iterative expansion.
    *
    * Starts with one empty combination and appends each digit's letters to every
    * existing combination, one digit at a time.
    *
    * Time complexity:
    * O(4^N * N) - up to 4 letters per digit, N digits, each combination length N
    *
    * Space complexity:
    * O(4^N * N) - storing all combinations
    */
    template<>
    std::vector<std::string> Solution<ver2>::letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }

        static const std::vector<std::string> phone{
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        std::vector<std::string> result{ "" };

        for (char digit : digits) {
            std::vector<std::string> temp;
            const std::string& letters = phone[digit - '0'];

            for (const std::string& combination : result) {
                for (char letter : letters) {
                    temp.push_back(combination + letter);
                }
            }

            result = std::move(temp);
        }

        return result;
    }

}
