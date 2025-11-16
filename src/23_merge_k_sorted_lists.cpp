#include "23_merge_k_sorted_lists.h"

#include <queue>

namespace _23_priority_queue {

    // priority_queue
    ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
            };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode temp;
        ListNode* tail = &temp;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) pq.push(node->next);
        }

        return temp.next;
    }

}

namespace _23_recursion {

    ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeSort(lists, 0, lists.size() - 1);
    }
    ListNode* Solution::mergeSort(std::vector<ListNode*>& lists, int lowerBound, int upperBound) {
        if (lowerBound == upperBound) {
            return lists[lowerBound];
        }

        int mid = lowerBound + (upperBound - lowerBound) / 2;
        ListNode* left = mergeSort(lists, lowerBound, mid);
        ListNode* right = mergeSort(lists, mid + 1, upperBound);

        return merge(left, right);
    }

    ListNode* Solution::merge(ListNode* leftPtr, ListNode* rightPtr) {
        ListNode temp;
        ListNode* tail = &temp;

        while (leftPtr && rightPtr) {
            if (leftPtr->val < rightPtr->val) {
                tail->next = leftPtr;
                leftPtr = leftPtr->next;
            }
            else {
                tail->next = rightPtr;
                rightPtr = rightPtr->next;
            }
            tail = tail->next;
        }
        tail->next = leftPtr ? leftPtr : rightPtr;

        return temp.next;
    }

}