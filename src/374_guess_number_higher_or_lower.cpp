#include "374_guess_number_higher_or_lower.h"


namespace _374 {

    /*
    * Classical binary search using an iterative approach.
    * Instead of calling a function again and again (recursion), the algorithm gradually updates values within the cycle, moving step-by-step towards problem resolution.
    * 
    * The operation of bitwise right shift by one position uses to get half the distance between the upper and lower bounds of the range.
    * It is equivalent to integer division by 2. Bit-shift operations execute much faster at the processor level compared to arithmetic division.
    * 
    * Time complexity:
    * O(logN)
    * 
    * Space complexity:
    * O(1)
    */
    int Solution::guessNumber(int num) {
        int low = 1;
        while (low <= num) {
            int curr_guess = low + ((num - low) >> 1);
            int result = guess(curr_guess);
            if (result == 0) {
                return curr_guess;
            }
            else if (result == 1) {
                low = curr_guess + 1;
            }
            else {
                num = curr_guess - 1;
            }
        }
        return low;
    }

    void Solution::setPick(int pick) {
        pdAPI.setPick(pick);
    }

    int Solution::guess(int num) {
        return pdAPI.guess(num);
    }

}