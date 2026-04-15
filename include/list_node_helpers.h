#ifndef LIST_NODE_HELPER_HEADER_FILE_h
#define LIST_NODE_HELPER_HEADER_FILE_h

#include "list_node.h"

#include <memory>
#include <string>
#include <vector>

class ListNodeHelper {
public:
    static ListNode* createList(const std::vector<int>& vals);
    static void freeList(ListNode* head);
    static std::string convertListNodeToString(ListNode* head);
    static void printList(ListNode* head);
};

struct ListNodeDeleter {
    void operator()(ListNode* head) const {
        ListNodeHelper::freeList(head);
    }
};
using UniqueListNode = std::unique_ptr<ListNode, ListNodeDeleter>;

#endif