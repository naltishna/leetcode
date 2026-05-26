#include "295_find_median_from_data_stream.h"

namespace _295 {

    /*
    * Approach: Two heaps.
    *
    * lowerHalf (max-heap) stores the smaller half of numbers,
    * upperHalf (min-heap) stores the larger half.
    * lowerHalf.size() is equal to upperHalf.size() or one greater.
    *
    * After each insert, heaps are rebalanced so sizes differ by at most 1.
    * Median is either the top of lowerHalf (odd total) or average of both tops (even total).
    *
    * Time complexity:
    * O(log n) - addNum - heap push/pop
    * O(1) - findMedian - top access only
    *
    * Space complexity:
    * O(n) - both heaps combined
    */
    void MedianFinder::addNum(int num) {
        if (lowerHalf.empty() || num <= lowerHalf.top()) {
            lowerHalf.push(num);
        }
        else {
            upperHalf.push(num);
        }

        // Balance the heaps so that the difference in size is at most 1.
        if (lowerHalf.size() > upperHalf.size() + 1) {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        }
        else if (upperHalf.size() > lowerHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }

    double MedianFinder::findMedian() const {
        if (lowerHalf.size() > upperHalf.size()) {
            return static_cast<double>(lowerHalf.top());
        }

        return (static_cast<double>(lowerHalf.top()) + upperHalf.top()) / 2.0;
    }

}
