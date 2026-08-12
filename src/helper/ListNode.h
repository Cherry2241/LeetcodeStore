#pragma once

struct ListNode {
    int val;
    ListNode* next;

    explicit ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode* nextNode) : val(value), next(nextNode) {}
};
