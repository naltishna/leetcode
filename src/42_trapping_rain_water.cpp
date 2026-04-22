#include "42_trapping_rain_water.h"
#include "class_version.h"

#include <algorithm>

namespace _42 {

    /*
    * Time complexity:
    * O(n)
    * 
    * Space complexity:
    * O(n)
    */
    template<>
    int Solution<ver1>::trap(std::vector<int>& height) {
        int n = height.size();
        if (n <= 1) {
            return 0; // Water cannot stay here because there is no walls to hold it.
        }

        std::vector<int> waterLeftMax(height.size());
        int max = waterLeftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            max = std::max(max, height[i]);
            waterLeftMax[i] = max;
        }

        std::vector<int> waterRightMax(height.size());
        max = waterRightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            max = std::max(max, height[i]);
            waterRightMax[i] = max;
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (std::min(waterLeftMax[i], waterRightMax[i]) - height[i]);
        }

        return sum;
    }

    /*
    * Shrink the window from both sides, always moving the pointer with the lower max wall.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::trap(std::vector<int>& height) {
        int n = height.size();
        if (n <= 1) {
            return 0; // Water cannot stay here because there is no walls to hold it.
        }

        int leftPtr = 0;
        int rightPtr = n - 1;
        int maxHeightFromLeft = height[leftPtr];
        int maxHeightFromRight = height[rightPtr];
        int sum = 0;

        while (leftPtr < rightPtr) {
            if (maxHeightFromLeft < maxHeightFromRight) {
                maxHeightFromLeft = std::max(maxHeightFromLeft, height[++leftPtr]);
                sum += maxHeightFromLeft - height[leftPtr];
            }
            else {
                maxHeightFromRight = std::max(maxHeightFromRight, height[--rightPtr]);
                sum += maxHeightFromRight - height[rightPtr];
            }
        }

        return sum;
    }

}