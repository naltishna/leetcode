#include "23_merge_k_sorted_lists.h"

#include <queue>

namespace _23_priority_queue {

    /*
     * Time complexity:
     * O(N Log K), where N is the total number of nodes in all lists
     *
     * Space complexity:
     * O(K), where K - number non empty elements
     */
    ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
            };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto node : lists) {
            if (node) {
                pq.push(node);
            }
        }

        ListNode temp;
        ListNode* tail = &temp;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) {
                pq.push(node->next);
            }
        }

        return temp.next;
    }

}

/**
* Each level of recursion splits the lists in half (≈ log K levels). At each level, a total of O(N) elements are merged.
*
* mergeSort(0,2)
│
├─ mergeSort(0,1)
│ ├─ mergeSort(0,0) → [1,4,5]
│ ├─ mergeSort(1,1) → [1,3,4]
│ └─ merge([1,4,5], [1,3,4]) → [1,1,3,4,4,5]
│
├─ mergeSort(2,2) → [2,6]
└─ merge([1,1,3,4,4,5], [2,6]) → [1,1,2,3,4,4,5,6]
*
* Note:
* The merge func returns a pointer to the next node of a local temp ListNode object.
* This does not create a dangling pointer because the nodes themselves are not created on the stack but are from the input lists.
* The temp node is just a placeholder on the stack to build the merged list. The temp.next points to the first node of the merged list.
* The temp's lifetime ends when the function returns, but temp.next points to nodes outside that local object.
* So, it is a valid pointer to a merged linked list consisting of nodes originally from the input lists.
* It is not a dangling pointer as long as the nodes in input lists remain valid.
*
* Time complexity:
* O(N Log K), where N is the total number of nodes in all lists
*
* Space complexity:
* O(1)
*/
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