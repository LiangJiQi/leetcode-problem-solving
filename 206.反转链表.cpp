/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        if(!head->next)return head;
        auto pList = head->next;
        auto pNext = head->next->next;
        //三指针，head当前指针的前指针，pList当前指针，pNext当前指针的下一指针，
        //在head和pList之间做反转
        do
        {
            if(pList->next == nullptr)//如果当前指针没有下一指针
            {
                pList->next = head;//接上前指针就可以返回了
                if(head->next == pList)head->next = nullptr;//特殊情况处理，当前指针是头节点时，尾巴要去掉不能形成环
                return pList;
            }
            else
            {
                pNext = pList->next;//还有下一指针
            }
            pList->next = head;//反转next为前指针
            if(head->next == pList)head->next = nullptr;//特殊情况处理，当前指针是头节点时，尾巴要去掉不能形成环
            head = pList;//前指针移到当前指针
            pList = pNext;//当前指针向后移至后指针
        } while (true);
        
    }
};
// @lc code=end

