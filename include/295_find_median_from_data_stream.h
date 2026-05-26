/*
https://leetcode.com/problems/find-median-from-data-stream/description/

295. Find Median from Data Stream

The median is the middle value in an ordered integer list. If the size of the list is even,
there is no middle value, and the median is the mean of the two middle values.

Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far.

Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);
medianFinder.addNum(2);
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);
medianFinder.findMedian(); // return 2.0

Constraints:
-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 10^4 calls will be made to addNum and findMedian.

Follow up:
If all integer numbers from the stream are in the range [0, 100], how would you optimize?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize?
*/

#pragma once

#include <functional>
#include <queue>
#include <vector>

namespace _295 {

    class MedianFinder {
    public:
        MedianFinder() = default;

        void addNum(int num);

        double findMedian() const;

    private:
        // max-heap - the top element is the largest element.
        std::priority_queue<int> lowerHalf;
        // min-heap - the top element is the smallest element.
        std::priority_queue<int, std::vector<int>, std::greater<int>> upperHalf;
    };

}
