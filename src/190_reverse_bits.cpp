#include "190_reverse_bits.h"

#include <bitset>
#include <string>
#include <bit>
#include <iostream>

namespace _190 {

    /*
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(N)
    */
    template<>
    int Solution<ver1>::reverseBits(int n) {
        int startBit = 32;

        std::string s;
        s.reserve(startBit);

        for (int i = startBit - 1; i >= 0; i--) {
            s += ((n >> i) & 1) + '0';
        }

        std::reverse(s.begin(), s.end());

        return std::stoi(s, nullptr, 2);
    }

    /*
    * Iterates through all 32 bits: each iteration extracts the LSB (Least Significant Bit)
    * of value (value & 1) and appends it to result by shifting left and OR-ing. Then shifts value right by 1.
    * 
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::reverseBits(int n) {
        // Cast to unsigned to guarantee logical right shifts (zero-fill) during bit reversal.
        unsigned int value = static_cast<unsigned int>(n);
        unsigned int result = 0;

        // Reverse bits of a given 32 bits signed integer.
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (value & 1U);
            value >>= 1;
        }

        return static_cast<int>(result);
    }

}