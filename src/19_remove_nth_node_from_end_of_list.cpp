#include "19_remove_nth_node_from_end_of_list.h"
#include "class_version.h"

namespace _19 {

    /*
    * Two-pass approach with a dummy (sentinel) node.
    *
    * First pass: traverse the full list to get its size.
    * Second pass: walk size - n steps from a dummy node placed before head
    * to land on the node before the target, then unlink it.
    *
    * The dummy node eliminates the edge case where the head itself is removed.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template <>
    ListNode* Solution<ver1>::removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0) return head;

        unsigned size = 0;
        for (ListNode* curr = head; curr; curr = curr->next) {
            ++size;
        }

        ListNode temp;
        temp.next = head;
        ListNode* before = &temp;

        for (int i = 0; i < size - n; ++i) {
            before = before->next;
        }

        if (ListNode* to_remove = before->next) {
            before->next = to_remove->next;
        }

        return temp.next;
    }

    /*
    * One-pass with two pointers behind a sentinel.
    *
    * Advance `lead` so it is (n + 1) steps ahead of `trail`; then slide both until
    * `lead` is null; `trail` ends up immediately before the node to remove.
    *
    * Time: O(N)
    *
    * Space: O(1)
    */
    template <>
    ListNode* Solution<ver2>::removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0) {
            return head;
        }

        ListNode temp;
        temp.next = head;
        ListNode* lead = &temp;

        for (int i = 0; i <= n; ++i) {
            lead = lead->next;
        }

        ListNode* trail = &temp;
        while (lead) {
            lead = lead->next;
            trail = trail->next;
        }

        if (ListNode* to_remove = trail->next) {
            trail->next = to_remove->next;
        }

        return temp.next;
    }

}