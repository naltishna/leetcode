#include "374_guess_number_higher_or_lower.h"


namespace _374 {

    int Solution::guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int result = guess(mid);
            if (result == 0) return mid;
            if (result == 1) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    void Solution::setPick(int pick) {
        pdAPI.setPick(pick);
    }

    int Solution::guess(int num) {
        return pdAPI.guess(num);
    }

}