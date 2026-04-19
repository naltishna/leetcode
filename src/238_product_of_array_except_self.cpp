#include "238_product_of_array_except_self.h"
#include "class_version.h"

namespace _238 {

    /*
    * Time complexity:
    * O(n²)
    *
    * Space complexity:
    * O(1), Note: According the task condition, the output array does not count as extra space for space complexity analysis.
    */
    template<>
    std::vector<int> Solution<ver1>::productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n);

        int ans = 1;
        for (int curr = 0; curr <= n - 1; ++curr) {
            for (int next = n - 1; next >= 0; --next) {
                if (next == curr) 
                    continue;

                ans *= nums[next];
            }
            res[curr] = ans;
            ans = 1;
        }

        return res;
    }


    /*
    * First pass (left → right): store in res[i] the product of all elements to the left of i.
    * Second pass (right → left): multiply res[i] by the running product of all elements to the right of i.
    * 
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1), Note: According the task condition, the output array does not count as extra space for space complexity analysis.
    */
    template<>
    std::vector<int> Solution<ver2>::productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, 1);

        int left_pass = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = left_pass;
            left_pass *= nums[i];
        }

        int right_pass = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right_pass;
            right_pass *= nums[i];
        }

        return res;
    }

}