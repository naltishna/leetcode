#include "66_plus_one.h"
#include "class_version.h"

#include <string>

namespace _66 {

    /*
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    std::vector<int> Solution<v1>::plusOne(std::vector<int>& digits) {
        int n = digits.size();
        unsigned long long number = 0LL;

        for (int i = 0; i < n; ++i) {
            number = number * 10 + digits[i];
        }

        number += 1;
        
        std::string numStr = std::to_string(number);
        int count = numStr.length();

        std::vector<int> res;
        for (int j = 0; j < count; ++j) {
            res.push_back(numStr[j] - '0');
        }

        return res;
    }

    /*
    * Right-to-left approach efficiently handles all cases of incrementing a number.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    std::vector<int> Solution<v2>::plusOne(std::vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // case: [9, 9, 9] -> [1, 0, 0, 0]
        digits.insert(digits.begin(), 1);

        return digits;
    }

}