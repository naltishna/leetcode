#include "92_reverse_linked_list_II.h"

namespace _92 {

    /*
    * Use a dummy node before head, move a pointer "before" to the node just before position left,
    * then iteratively take the node after current and move it to after "before" (head-insertion)
    * for right−left times to reverse the sublist in-place.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    ListNode* Solution::reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode temp;
        temp.next = head;
        ListNode* before = &temp;

        for (int i = 0; i < left - 1; ++i) {
            before = before->next;
        }

        ListNode* current = before->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* target = current->next;
            current->next = target->next;
            target->next = before->next;
            before->next = target;
        }

        return temp.next;
    }

}