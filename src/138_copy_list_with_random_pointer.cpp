#include "138_copy_list_with_random_pointer.h"
#include "class_version.h"

#include <unordered_map>

namespace _138_raw {

    /*
    * Interleaved clone list:
    * 
    * Weave clones in - insert each clone node directly after its original, turning A->B->C into A->A'->B->B'->C->C'.
    * Fix random pointers - since the clone of any node x is always x->next, setting curr->next->random = curr->random->next correctly wires random pointers per node.
    * Unweave - split the interleaved list back into the original and the clone list.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    Node* Solution<ver1>::copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Create clones and insert them immediately after the originals.
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Copy random pointers.
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Separate the two lists (restore the original and extract the copy).
        Node* temp = new Node(0);
        Node* copyCurr = temp;

        curr = head;
        while (curr) {
            copyCurr->next = curr->next;
            curr->next = curr->next->next;

            copyCurr = copyCurr->next;
            curr = curr->next;
        }

        Node* copyHead = temp->next;
        delete temp;

        return copyHead;
    }

    /*
    * Hash map from original node to its clone. Straightforward two-pass build.
    * Time: O(n). Extra space: O(n) for the map (ver1 uses O(1) extra space).
    */
    template<>
    Node* Solution<ver2>::copyRandomList(Node* head) {
        if (!head) return nullptr;

        unsigned n = 0;
        for (Node* curr = head; curr; curr = curr->next) {
            ++n;
        }

        std::unordered_map<Node*, Node*> oldToNew;
        oldToNew.reserve(n);

        for (Node* curr = head; curr; curr = curr->next) {
            oldToNew.emplace(curr, new Node(curr->val));
        }

        // Each clone already exists in the map; connect next/random to other clones.
        for (Node* curr = head; curr; curr = curr->next) {
            Node* copy = oldToNew[curr];
            copy->next = curr->next ? oldToNew[curr->next] : nullptr;
            copy->random = curr->random ? oldToNew[curr->random] : nullptr;
        }

        return oldToNew[head];
    }

}

namespace _138_smart_ptr {

    /*
    * Smart-pointer version:
    * shared_ptr for ownership through next, weak_ptr for random to avoid ownership cycles.
    * Time: O(n). Extra space: O(n) for the map.
    */
    template<>
    std::shared_ptr<SmartNode> Solution<ver1>::copyRandomList(const std::shared_ptr<SmartNode>& head) {
        if (!head) return nullptr;

        std::unordered_map<const SmartNode*, std::shared_ptr<SmartNode>> oldToNew;

        for (std::shared_ptr<SmartNode> curr = head; curr; curr = curr->next) {
            oldToNew.emplace(curr.get(), std::make_shared<SmartNode>(curr->val));
        }

        for (std::shared_ptr<SmartNode> curr = head; curr; curr = curr->next) {
            std::shared_ptr<SmartNode> copy = oldToNew[curr.get()];
            copy->next = curr->next ? oldToNew[curr->next.get()] : nullptr;

            if (std::shared_ptr<SmartNode> randomNode = curr->random.lock()) {
                copy->random = oldToNew[randomNode.get()];
            } else {
                copy->random.reset();
            }
        }

        return oldToNew[head.get()];
    }

    /*
    * Smart-pointer version:
    * shared_ptr for ownership through next, weak_ptr for random to avoid ownership cycles.
    * Time: O(n). Extra space: O(1) for the map.
    */
    template<>
    std::shared_ptr<SmartNode> Solution<ver2>::copyRandomList(const std::shared_ptr<SmartNode>& head) {
        if (!head) return nullptr;

        // 1) Interleave copied nodes after original nodes.
        std::shared_ptr<SmartNode> curr = head;

        while (curr) {
            std::shared_ptr<SmartNode> copy = std::make_shared<SmartNode>(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // 2) Assign random pointers for copied nodes.
        curr = head;
        while (curr) {
            std::shared_ptr<SmartNode> randomNode = curr->random.lock();
            if (randomNode) {
                curr->next->random = randomNode->next;
            } else {
                curr->next->random.reset();
            }
            curr = curr->next->next;
        }

        // 3) Split interleaved list into original and copied lists.
        std::shared_ptr<SmartNode> dummy = std::make_shared<SmartNode>(0);
        std::shared_ptr<SmartNode> copyCurr = dummy;
        curr = head;

        while (curr) {
            std::shared_ptr<SmartNode> copy = curr->next;
            copyCurr->next = copy;
            curr->next = copy->next;

            copyCurr = copy;
            curr = curr->next;
        }

        return dummy->next;
    }

}