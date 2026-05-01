#include "191_number_of_1_bits.h"

namespace _191 {

    /*
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver1>::hammingWeight(int n) {
        unsigned int value = static_cast<unsigned int>(n);
        int result = 0;

        // The loop is executed as many times as there are bits in "n" until the number becomes zero.
        while (value != 0U) {
            result += (value & 1U);
            value >>= 1;
        }

        return result;
    }

    /*
    * Each iteration clears the lowest set bit of value via value &= (value - 1),
    * and increments the counter. The loop runs exactly as many times as there are 1-bits,
    * making it more efficient than checking all 32 bits.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::hammingWeight(int n) {
        unsigned int value = static_cast<unsigned int>(n);
        int count = 0;

        // The loop will be executed exactly as many times as there are ones in "n".
        while (value != 0U) {
            value &= (value - 1U);
            ++count;
        }

        return count;
    }

}