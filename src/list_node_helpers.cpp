#include "list_node_helpers.h"

#include <iostream>
#include <unordered_set>

ListNode* ListNodeHelper::createList(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;

    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void ListNodeHelper::freeList(ListNode* head) {
    std::unordered_set<ListNode*> visited;

    while (head) {
        // We've already visited this node, so the loop is closed.
        if (visited.find(head) != visited.end()) {
            break;
        }

        visited.insert(head);
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

/*
* Pool: all nodes that were linked from the original head before an in-place removal.
*/
void ListNodeHelper::deleteNodesAbsentFromChain(ListNode* chain_head, const std::vector<ListNode*>& pool) {
    std::unordered_set<ListNode*> reachable;

    for (ListNode* p = chain_head; p; p = p->next) {
        reachable.insert(p);
    }

    for (ListNode* p : pool) {
        if (reachable.find(p) == reachable.end()) {
            delete p;
        }
    }
}

std::string ListNodeHelper::convertListNodeToString(ListNode* head) {
    std::string ss = "{ ";

    if (!head) {
        ss.append("}");
        return ss;
    }

    while (head) {
        ss.append(std::to_string(head->val));
        head = head->next;

        if (head) {
            ss.append(", ");
        }
    }

    ss.append(" }");

    return ss;
}

void ListNodeHelper::printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}