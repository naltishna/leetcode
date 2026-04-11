#include "206_reverse_linked_list.h"

namespace _206 {

    /*
    * Maintain two pointers — prev (initially null) and current (initially head).
    * On each step, save current->next, redirect current->next to prev, then advance both pointers forward.
    * When current reaches null, prev is the new head.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    ListNode* Solution::reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }

        return prev;
    }

}