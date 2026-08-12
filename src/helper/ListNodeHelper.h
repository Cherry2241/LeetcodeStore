#pragma once

#include <initializer_list>
#include <vector>

#include "helper/ListNode.h"

namespace helper {

inline ListNode* MakeList(std::initializer_list<int> values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return dummy.next;
}

inline std::vector<int> ToVector(const ListNode* head) {
    std::vector<int> values;
    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }
    return values;
}

inline void FreeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

}  // namespace helper
