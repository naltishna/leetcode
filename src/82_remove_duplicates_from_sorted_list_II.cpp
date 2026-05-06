#include "82_remove_duplicates_from_sorted_list_II.h"

namespace _82 {

    /*
    * Scan each 'current' value, use 'nextTemp' to skip all nodes sharing value.
    * If duplicates were found, delete the entire group and relink 'prev' directly to 'nextTemp'.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    ListNode* Solution::deleteDuplicates(ListNode* head) {
        ListNode temp;
        temp.next = head;
        ListNode* prev = &temp;
        ListNode* current = head;

        while (current) {
            ListNode* nextTemp = current->next;
            while (nextTemp && nextTemp->val == current->val) {
                nextTemp = nextTemp->next;
            }

            if (current->next != nextTemp) {
                ListNode* node = current;

                while (node != nextTemp) {
                    ListNode* next = node->next;
                    delete node;
                    node = next;
                }

                prev->next = nextTemp;
                current = nextTemp;
            }
            else {
                prev = current;
                current = current->next;
            }
        }

        return temp.next;
    }

}