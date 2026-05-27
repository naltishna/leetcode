#include "148_sort_list.h"

#include <queue>
#include <vector>

namespace _148 {

    /*
    * Approach: Priority queue.
    *
    * Push all nodes into a min-heap, then pop them out in sorted order rebuilding the list.
    *
    * Time complexity:
    * O(N log N) - N pushes + N pops, each O(log N)
    *
    * Space complexity:
    * O(N) - all nodes stored in heap
    */
    ListNode* Solution::sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
            };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

        while (head != nullptr) {
            ListNode* next = head->next;
            pq.push(head);
            head = next;
        }

        ListNode temp;
        ListNode* tail = &temp;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
        }

        tail->next = nullptr;

        return temp.next;
    }

}
