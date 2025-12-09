//
// Created by wanghaichao on 2025/12/9.
//
#include "common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* getMiddle(ListNode* head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur=nxt;
        }
        return pre;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *mid = getMiddle(head);
        ListNode *head2 = reverse(mid);
        while(head2){
            if(head->val != head2->val){
                return false;
            }

            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};

// 测试用例：匹配题目中的Example1
TEST(isPalindrome, Example1) {
    Solution s;

    std::vector<int> input = {1, 2, 3, 2, 1};          // 公共交点部分
    ListNode *head = createList(input);
    bool res = s.isPalindrome(head);
    ASSERT_EQ(res, true);
}
