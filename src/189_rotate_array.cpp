#include "189_rotate_array.h"
#include "class_version.h"

namespace _189 {

    /*
    * Determine the actual shift using the modulo (%) to avoid unnecessary array rotation if the shift value exceeds the array length.
    *
    * For example, if you have an array of length 5 and k is 8, then it is more efficient to shift by 3 units (since 8%5=3) rather than by 8 units.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
     void Solution<v1>::rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return;
        }

        int shift = k % n;
        if (shift == 0) {
            return;
        }

        std::rotate(nums.rbegin(), nums.rbegin() + shift, nums.rend());
    }

    /*
    * The approach is not effective. It works very slow for large k.
    *
    * Array rotation using a simple element-by-element shifting method.
    *
    * Time complexity:
    * O(k x n), where k is the number of rotation cycles and n is the length of the array.
    *
    * Space complexity:
    * O(1)
    */
    void Solution<v2>::rotate(std::vector<int>& nums, int k) {
        size_t n = nums.size();
        if (n == 0) {
            return;
        }

        k = k % n;

        while (k-- > 0) {
            int temp = nums[n - 1];
            for (size_t i = n - 1; i > 0; --i) {
                nums[i] = nums[i - 1];
            }
            nums[0] = temp;
        }
    }

    /*
    * Two-pass algorithm.
    *
    * First pass: Filling the temporary array with the required shift.
    * Second pass: Replacing the contents of the original array with a new ordered set of values.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    void Solution<v3>::rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;

        std::vector<int> result(n);

        for (size_t i = 0; i < n; ++i) {
            // make ensure that indices in the new array remain valid
            result[(i + k) % n] = nums[i];
        }

        nums = std::move(result);
    }

    /*
    * Reverse algorithm.
    *
    Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    void Solution<v4>::rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;

        // Idea: reverse(all) -> reverse(first k) -> reverse(n-k)
        // [1,2,3,4,5,6,7], k=3 -> [7,6,5,4,3,2,1] -> [5,6,7,4,3,2,1] -> [5,6,7,1,2,3,4]
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }

    /*
    * Cyclic replacement.
    *
    * [1, 2, 3, 4, 5, 6, 7], k = 3
    * (0+3)%7=3: [__, __, __, 1, __, __, __], prev = 4
    * (3+3)%7=6: [__, __, __, 1, __, __, 4],  prev = 7
    * (6+3)%7=2: [__, __, 7, 1, __, __, 4],   prev = 3
    * (2+3)%7=5: [__, __, 7, 1, __, 3, 4],    prev = 6
    * (5+3)%7=1: [__, 6, 7, 1, __, 3, 4],     prev = 2
    * (1+3)%7=4: [_, 6, 7, 1, 2, 3, 4],       prev = 5
    * (4+3)%7=0: [5, 6, 7, 1, 2, 3, 4]
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    void Solution<v5>::rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;
        if (k == 0) return;

        int count = 0;

        for (int start = 0; count < n; ++start) {
            int current = start;
            int prev = nums[start];

            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }

}