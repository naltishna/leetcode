#include "228_summary_ranges.h"

namespace _228 {

    /*
    * Track the start of each consecutive run and extend it while nums[i] == prev + 1.
    * When the sequence breaks, flush the current range as either "a" or "a->b", then start a new one.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    std::vector<std::string> Solution::summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> output;
        if (nums.empty()) {
            return output;
        }

        int start = nums[0];
        int prev = nums[0];

        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            if (prev + 1 == nums[i]) {
                prev = nums[i];
            }
            else {
                std::string str;
                if (start == prev) {
                    str = std::to_string(start);
                }
                else {
                    str = std::to_string(start) + "->" + std::to_string(prev);
                }
                output.push_back(str);

                start = nums[i];
                prev = nums[i];
            }
        }

        if (start == prev) {
            output.push_back(std::to_string(start));
        }
        else {
            output.push_back(std::to_string(start) + "->" + std::to_string(prev));
        }

        return output;
    }

}