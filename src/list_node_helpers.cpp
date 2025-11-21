#include "list_node_helpers.h"

#include <iostream>

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
    while (head) {
        ListNode* temp = head;
        //std::cout << "Node deleted " << temp->val << std::endl;
        head = head->next;
        delete temp;
    }
}

std::string ListNodeHelper::convertListNodeToString(ListNode* head) {
    std::string ss;
    while (head) {
        ss.append(std::to_string(head->val));
        head = head->next;
    }
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