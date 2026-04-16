#include "155_min_stack.h"

#include <algorithm>

namespace _155_O_N {

    /*
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    MinStack::~MinStack() {
        clear();
    }

    void MinStack::clear() {
        while (topNode) {
            pop();
        }
    }

    void MinStack::push(int val) {
        topNode = new Node{ val, topNode };
    }

    void MinStack::pop() {
        if (!topNode) return;

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int MinStack::top() const {
        return topNode ? topNode->data : -1;
    }

    int MinStack::getMin() const {
        int min = std::numeric_limits<int>::max();
        Node* temp = topNode;
        while (temp) {
            min = std::min(min, temp->data);
            temp = temp->next;
        }
        return min;
    }

}

namespace _155_O_1 {

    /*
    * Each node stores its own minVal — the minimum at the time it was pushed.
    * This way getMin() is always O(1) without a separate auxiliary stack.
    * 
    * Time complexity:
    * O(1)
    * 
    * Space complexity:
    * O(n) 
    */
    MinStack::~MinStack() { // added to avoid Stack Overflow
        clear();
    }

    void MinStack::clear() {
        while (topNode) {
            pop();
        }
    }

    void MinStack::push(int val) {
        int currentMin = topNode ? std::min(val, topNode->minVal) : val;
        topNode = std::make_unique<Node>(Node{ val, currentMin, std::move(topNode) });
    }

    void MinStack::pop() {
        if (topNode) {
            topNode = std::move(topNode->next);
        }
    }

    int MinStack::top() const {
        return topNode ? topNode->data : -1;
    }

    int MinStack::getMin() const {
        return topNode->minVal;
    }

}