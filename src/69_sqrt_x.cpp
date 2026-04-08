#include "69_sqrt_x.h"

namespace _69 {

    /*
    * Using binary search to find the largest integer whose square is less than or equal to x.
    * 
    * Time complexity:
    * O(logN)
    * 
    * Space complexity:
    * O(1)
    */
    int Solution::mySqrt(int x) {
        if (x < 0) {
            return 0;
        }

        if (x == 0 || x == 1) {
            return x;
        }

        long long low = 0;
        long long high = x;
        int answer = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long mid_squared = mid * mid;

            if (mid_squared == x) {
                return static_cast<int>(mid);
            }
            else if (mid_squared < x) {
                answer = static_cast<int>(mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return answer;
    }

}