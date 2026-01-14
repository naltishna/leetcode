#include "2_add_two_numbers.h"

namespace _2 {

    /**
    * At each step, it sums:
    * The current digit from l1 (if l1 is not nullptr).
    * The current digit from l2 (if l2 is not nullptr).
    * The current value of num, which represented the carry from the previous step.
    * 
    Time complexity:
        O(max(N,M)) - The program must visit every node in the longer list once.

    Space complexity:
        O(max(N,M)) - The program creates a new result list whose length is proportional to the longer input list.
    */
    ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode temp;
        ListNode* tail = &temp;
        int num = 0;

        while (l1 || l2 || num) {
            num += (l1 ? l1->val : 0);
            num += (l2 ? l2->val : 0);

            tail->next = new ListNode(num % 10);
            tail = tail->next;
            num /= 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return temp.next;
    }

}