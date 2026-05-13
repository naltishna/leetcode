#include "61_rotate_list.h"

namespace _61 {

    /*
    * Circular list approach:
    *
    * - Find tail + measure length n;
    * - Reduce k %= n;
    * - Close the list into a ring (tail->next = head);
    * - Walk n - k steps to find the new tail;
    * - Break the ring, a new head is the (n-k+1)-th node.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    ListNode* Solution::rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }

        // Walk to the last node: count list length n and keep tail for later (close the list into a ring).
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++n;
        }

        // Rotating by n steps is a full cycle; only k % n affects the result (and keeps k small).
        k %= n;
        if (k == 0) {
            return head;
        }

        // Turn the list into a ring so we can walk from the old tail to the old head.
        tail->next = head;

        ListNode* newHead = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < n - k; ++i) {
            prev = newHead;
            newHead = newHead->next;
        }

        // Terminate the list at the last node, newHead becomes the list head.
        prev->next = nullptr;

        return newHead;
    }

}