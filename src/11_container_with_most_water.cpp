#include "11_container_with_most_water.h"

namespace _11 {

    /*
    * The task involves finding two vertical lines that form a container capable of holding the maximum amount of water between them.
    *
    * If the left side is lower than the right side, increasing its index to reach the height of the next candidate container.
    * Similarly, when the right side is smaller, reducing its index gives a chance to reach larger areas.
    *
    * Complexity
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    int Solution::maxArea(std::vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int max_area = 0;
        int start = 0, end = height.size() - 1;

        while (start < end) {
            if (height[start] < height[end]) {
                max_area = std::max(max_area, height[start] * (end - start));
                start++;
            }
            else {
                max_area = std::max(max_area, height[end] * (end - start));
                end--;
            }
        }

        return max_area;
    }

}