#include "125_valid_palindrome.h"

#include <algorithm>
#include <functional>

namespace _125 {

    /*
    * Use STL and two pointers.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    bool Solution::isPalindrome(std::string s) {
        auto isAlNum = [](auto ch) { return std::isalnum(ch); };
        auto toLower = [](auto ch) { return std::tolower(ch); };

        s.erase(std::remove_if(s.begin(), s.end(), std::not_fn(isAlNum)), s.end());
        std::transform(s.begin(), s.end(), s.begin(), toLower);

        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }

        return true;
    }

}