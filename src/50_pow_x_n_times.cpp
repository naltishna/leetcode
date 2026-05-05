#include "50_pow_x_n_times.h"
#include "class_version.h"

#include <cmath>

namespace _50 {

    /*
    * Fast exponentiation (binary exponentiation).
    * If the current bit is 1 then multiply result by the current power of x.
    * Square x (x = x²) to move to the next power of two.
    * Right-shift the exponent to process the next bit.
    *
    * Example: x^13, since 13 = 1101₂
    * result *= x^1 (bit 0 = 1)
    * skip x^2 (bit 1 = 0)
    * result *= x^4 (bit 2 = 1)
    * result *= x^8 (bit 3 = 1)
    * -> x^(1+4+8) = x^13
    *
    * Time complexity:
    * O(log n)
    *
    * Space complexity:
    * O(1)
    */
    template <>
    double Solution<ver1>::myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            // If n is negative, x^n = 1 / x^(-n).
            // Invert x and make the exponent positive.
            x = 1.0 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            // Check the lowest bit of exp: if it is 1, include the current power of x in the result
            // i.e., multiply by x^(2^k) for the corresponding set bit.
            if (exp & 1LL) {
                result *= x;
            }

            x *= x;

            // Shift exp right by 1 bit to move to the next power of two (2^(k+1)).
            // This effectively divides exp by 2 in the binary exponentiation loop.
            exp >>= 1;
        }

        return result;
    }

    /*
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template <>
    double Solution<ver2>::myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }

        double result = 1.0;
        for (long long i = 0; i < exp; i++) {
            result *= x;
        }

        return result;
    }

}