#ifndef HELPER_HEADER_FILE_h
#define HELPER_HEADER_FILE_h

#include "list_node.h"

#include <string>
#include <vector>

class ListNodeHelper {
public:
    static ListNode* createList(const std::vector<int>& vals);
    static void freeList(ListNode* head);
    static std::string convertListNodeToString(ListNode* head);
    static void printList(ListNode* head);

};

#endif