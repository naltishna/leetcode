#include "202_happy_number.h"

#include <unordered_set>

namespace _202 {

    /*
    * Stores every seen number. Inner loop extracts digits and accumulates sum of squares via % 10 and / 10.
    * If n repeats the cycle detected, it is not happy. If n reaches 1, it is happy.
    * 
    * Time complexity:
    * O(log n)
    * 
    * Space complexity:
    * O(log n) — entries in the set before a cycle or 1 is reached
    */
    bool Solution::isHappy(int n) {
        std::unordered_set<int> seen;

        while (n != 1 && !seen.contains(n)) {
            seen.insert(n);

            int sum = 0;
            while (n > 0) {
                const int digit = n % 10;
                n /= 10;
                sum += digit * digit;
            }

            n = sum;
        }

        return n == 1;
    }

}