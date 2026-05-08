#include "172_factorial_trailing_zeroes.h"

namespace _172 {

    /*
    * Repeatedly divide n by 5, accumulating each coefficient into count:
    * n=100: 100/5=20 → count=20
    *         20/5=4 → count=24
    *          4/5=0 → stop
    *
    * Each division step counts how many multiples of the power of 5 (5¹, 5², 5³...) fit into n.
    * This implicitly handles numbers like 25 or 125 that contribute extra multiplier of 5.
    *
    * Time complexity:
    * O(logN)
    *
    * Space complexity:
    * O(1)
    */
    int Solution::trailingZeroes(int n) {
        int count = 0;

        // Trailing zeros in n! equal how many times 5 appears in numbers from 1 to n.
        while (n > 0) {
            n /= 5;
            count += n;
        }

        return count;
    }

}