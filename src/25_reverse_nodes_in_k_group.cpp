#include "25_reverse_nodes_in_k_group.h"

namespace _25 {

    /*
    * First pass counts size to know how many full groups exist (size / k).
    * For each group, reverse k nodes in-place using standard pointer reversal,
    * then relink the previous group's tail to the new head and the new tail to the remaining list.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    ListNode* Solution::reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        unsigned size = 0;
        for (ListNode* curr = head; curr; curr = curr->next) {
            ++size;
        }

        ListNode temp;
        temp.next = head;
        ListNode* prev_group_end = &temp;
        ListNode* curr = head;

        // Only full groups of k are reversed.
        for (int i = 0; i < size / k; ++i) {
            ListNode* group_start = curr;
            ListNode* prev = nullptr;

            for (int j = 0; j < k; ++j) {
                ListNode* next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }

            prev_group_end->next = prev;     // Previous tail -> new group head.
            group_start->next = curr;        // New tail (old start) -> next node.
            prev_group_end = group_start;    // Move the group-end marker forward.
        }

        return temp.next;
    }

}