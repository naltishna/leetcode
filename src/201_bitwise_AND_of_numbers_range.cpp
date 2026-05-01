#include "201_bitwise_AND_of_numbers_range.h"
#include "class_version.h"

namespace _201 {

    /*
    * Repeatedly right-shift both left and right until they're equal — that finds their common
    * high-order bit prefix. Then shift back left by the same count to restore value.
    *
    * The idea: any bits that differ between left and right will be zeroed out in the AND
    * of the entire range, so only the shared prefix survives.
    *
    * Time complexity:
    * O(logN)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver1>::rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }

        return left << shift;
    }

    /*
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = right & (right - 1);
        }

        return right;
    }

}