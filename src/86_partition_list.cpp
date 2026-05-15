#include "86_partition_list.h"
#include "class_version.h"

namespace _86 {

    /*
    * Build two chains: nodes with val < x (preserve order) and nodes with val >= x.
    *
    * Maintain two separate sub-lists in a single pass:
    *
    * less — nodes with val < x
    * geq — nodes with val >= x
    *
    * Each sub-list has a dummy head node (stack-allocated sentinel) so you never need to special-case an empty list.
    * After the loop, splice the two chains together: less tail -> geq head.
    *
    * The order of nodes within each partition is preserved, because you always append to the tail of each chain.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    ListNode* Solution<ver1>::partition(ListNode* head, int x) {
        ListNode lessHead;
        ListNode geqHead;

        // Nodes with value less than x (val < x).
        ListNode* lessTail = &lessHead;
        // Nodes with value greater than or equal to x (val >= x).
        ListNode* geqTail = &geqHead;

        for (ListNode* curr = head; curr;) {
            if (curr->val < x) {
                // Line is needed to connect the nodes into a chain.
                lessTail->next = curr;
                // Line is needed to avoid losing the tail for the next iteration.
                lessTail = curr;
            }
            else {
                geqTail->next = curr;
                geqTail = curr;
            }

            curr = curr->next;
        }

        // Last node in the >= x chain may still point into the old list, so cut the tail to end the result list.
        geqTail->next = nullptr;
        // Link the < x chain to the >= x chain (geqHead.next is the first real node after the dummy).
        lessTail->next = geqHead.next;

        return lessHead.next;
    }

    /*
    * Same two-chain partition as ver1, but without dummy nodes: track head/tail per chain explicitly.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    ListNode* Solution<ver2>::partition(ListNode* head, int x) {
        // Head and tail of the chain with val < x.
        ListNode* lessHead = nullptr;
        ListNode* lessTail = nullptr;

        // Head and tail of the chain with val >= x.
        ListNode* geqHead = nullptr;
        ListNode* geqTail = nullptr;

        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                // First node in the < x chain: set both head and tail.
                if (lessHead == nullptr) {
                    lessHead = curr;
                    lessTail = curr;
                }
                else {
                    lessTail->next = curr;
                    lessTail = curr;
                }
            }
            else {
                // First node in the >= x chain: set both head and tail.
                if (geqHead == nullptr) {
                    geqHead = curr;
                    geqTail = curr;
                }
                else {
                    geqTail->next = curr;
                    geqTail = curr;
                }
            }

            curr = curr->next;
        }

        // Cut stale links from the last node in the >= x chain.
        if (geqTail != nullptr) {
            geqTail->next = nullptr;
        }

        if (lessHead == nullptr) {
            // No nodes < x; the result is the >= x chain only.
            return geqHead;
        }

        // Append the >= x chain after the < x chain.
        lessTail->next = geqHead;

        return lessHead;
    }

}