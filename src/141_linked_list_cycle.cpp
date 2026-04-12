#include "141_linked_list_cycle.h"

namespace _141 {

    /*
    * Two pointers start at the head — slow moves one step at a time, fast moves two steps.
    * If a cycle exists, the fast pointer will eventually lap the slow one and they'll meet.
    * If there's no cycle, the fast pointer reaches the end (nullptr).
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    bool Solution::hasCycle(ListNode* head) {
        // If the list is empty or consists of a single node
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // move one step
            fast = fast->next->next;    // move two steps

            // If they met, it means there is a cycle inside
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

}