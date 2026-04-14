#include "21_merge_two_sorted_lists.h"

namespace _21 {

    /*
    * 1. Create a dummy node temp as a sentinel.
    * 2. Maintain a tail pointer to the last merged node.
    * 3. At each step, compare heads of both lists — attach the smaller one to tail, advance that list.
    * 4. When one list is exhausted, attach the remaining list directly.
    * 
    * Time complexity:
    * O(n + m)
    * 
    * Space complexity:
    * O(1)
    */
    ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp;
        ListNode* tail = &temp;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;

        return temp.next;
    }

}