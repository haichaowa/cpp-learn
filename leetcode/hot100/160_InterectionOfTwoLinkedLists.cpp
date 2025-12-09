//
// Created by wanghaichao on 2025/12/7.
//
#include "common.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while(p1 != p2){
            p1 = p1 != nullptr ? p1->next : headB;
            p2 = p2 != nullptr ? p2->next : headA;
        }
        return p1;
    }
};


// 辅助函数：连接两个链表（让list1的尾节点指向list2的指定索引节点，制造交点）
// skipA：list1中交点前的节点数（即list1尾节点连接到list2的第skipB个节点，索引从0开始）
// skipB：list2中交点的起始索引（0表示从list2头节点开始相交）
void connectLists(ListNode* list1, ListNode* list2, int skipA, int skipB) {
    // 找到list1的尾节点
    ListNode* curr1 = list1;
    for (int i = 0; i < skipA && curr1 != nullptr; ++i) {
        curr1 = curr1->next;
    }
    if (curr1 == nullptr) return;  // 异常防护

    // 找到list2中交点的起始节点
    ListNode* curr2 = list2;
    for (int i = 0; i < skipB && curr2 != nullptr; ++i) {
        curr2 = curr2->next;
    }
    if (curr2 == nullptr) return;  // 异常防护

    // 让list1的尾节点指向list2的交点节点（制造相交）
    curr1->next = curr2;
}


// 测试用例：匹配题目中的Example1
TEST(getIntersectionNode, Example1) {
    Solution s;

    // 题目输入：
    // listA = [4,1,8,4,5]，skipA=2（交点前有2个节点：4、1）
    // listB = [5,6,1,8,4,5]，skipB=3（交点前有3个节点：5、6、1）
    // 交点节点值为8（且是同一个内存地址的节点）

    // 步骤1：创建“交点前的链表”和“公共交点链表”
    std::vector<int> listA_prefix = {4, 1};       // A的非公共部分
    std::vector<int> listB_prefix = {5, 6, 1};    // B的非公共部分
    std::vector<int> common = {8, 4, 5};          // 公共交点部分

    // 步骤2：构建链表
    ListNode* headA = createList(listA_prefix);
    ListNode* headB = createList(listB_prefix);
    ListNode* common_head = createList(common);  // 公共部分链表（交点从8开始）

    // 步骤3：连接链表，制造交点
    // skipA=2：A的尾节点（1的下一个）连接到公共链表头（8）
    // skipB=3：B的尾节点（1的下一个）连接到公共链表头（8）
    connectLists(headA, common_head, listA_prefix.size() - 1, 0);
    connectLists(headB, common_head, listB_prefix.size() - 1, 0);

    // 步骤4：执行测试，验证结果
    ListNode* result = s.getIntersectionNode(headA, headB);
    ASSERT_NE(result, nullptr);                  // 确保交点不为空
    ASSERT_EQ(result->val, 8);                   // 验证交点值为8
    ASSERT_EQ(result, common_head);              // 验证是同一个内存地址的节点（关键：不是值相等，而是节点相同）

    // 步骤5：释放内存
    ListNode* b_tail = headB;
    while (b_tail != nullptr && b_tail->next != common_head) {
        b_tail = b_tail->next;
    }
    if (b_tail != nullptr) {
        b_tail->next = nullptr; // 切断B与公共链表的连接
    }
    freeList(headA);  // 会连带释放common_head（因为headA->next指向common_head）
    freeList(headB);  // B的next也指向common_head，但重复释放会出错，这里调整：让headB的尾节点不重复释放
}

// 额外补充：无交点的测试用例（确保边界场景正确）
TEST(getIntersectionNode, NoIntersection) {
    Solution s;

    std::vector<int> listA = {4, 1, 8, 4, 5};
    std::vector<int> listB = {5, 6, 1, 2, 3};  // 无公共部分

    ListNode* headA = createList(listA);
    ListNode* headB = createList(listB);

    ListNode* result = s.getIntersectionNode(headA, headB);
    ASSERT_EQ(result, nullptr);  // 无交点，返回NULL

    // 释放内存
    freeList(headA);
    freeList(headB);
}
