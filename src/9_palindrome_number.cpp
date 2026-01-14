#include "9_palindrome_number.h"

#include <cstdlib>

namespace _9 {

    /*
    * Using division and the modulo operator, the digits of the number are extracted one by one, starting with the last one.
    * The digits are added together in reverse order to form a new number.
    *
    * Time complexity:
    * O(Log(N))
    *
    * Space complexity:
    * O(1)
    */
    bool Solution::isPalindrome(int x) {
        // Negative number and number ending in zero (except zero itself) cannot be palindrome 
        // (e.g., -121 is not 121-, 10, 100 and so on are not palindromes)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int original_x = x;
        long long new_number = 0;

        while (x > 0) {
            new_number = (new_number * 10) + (x % 10);
            x /= 10;
        }

        return original_x == new_number;
    }

}