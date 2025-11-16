#include "2_add_two_numbers.h"

namespace _2 {

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