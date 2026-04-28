#include "137_single_number_II.h"

namespace _137 {

    /*
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver1>::singleNumber(std::vector<int>& nums) {
        int result = 0;
        const int totalBits = static_cast<int>(sizeof(int) * 8);

        for (int bit = 0; bit < totalBits; ++bit) {
            int bitCount = 0;
            int mask = (1 << bit);

            for (int num : nums) {
                if ((num & mask) != 0) {
                    ++bitCount;
                }
            }

            if ((bitCount % 3) != 0) {
                result |= mask;
            }
        }

        return result;
    }

    /*
    * Uses two accumulators (ones, twos) to track bits seen 1 and 2 times respectively.
    * For each number, bits appearing a 3rd time are cleared from both.
    * After processing, ones holds bits seen exactly once — the unique element.
    * 
    * This solution is 32 times faster than the first option in terms of the number of operations.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::singleNumber(std::vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }

}