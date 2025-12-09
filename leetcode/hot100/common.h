//
// Created by wanghaichao on 2025/7/30.
//

#ifndef CPP_LEARN_COMMON_H
#define CPP_LEARN_COMMON_H

#include <array>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;

// 链表
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}

    explicit ListNode(int x): val(x), next(nullptr){}

    ListNode(int x, ListNode *next): val(x), next(next){}
};

ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

void freeList(ListNode* head) {
    ListNode* temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

#endif //CPP_LEARN_COMMON_H
