/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {

        //快慢指针法，慢指针每次走next一次，快指针每次next两次，当快慢有任何一个为空说明此链表无环
        //当快指针追到了慢指针说明次链表有环
        if(head == nullptr)return false;
        if(head->next == nullptr)return false;
        auto pLow = head;
        auto pFast = head->next;
        do
        {
            if(pLow == nullptr || pFast == nullptr)return false;//当快慢有任何一个为空说明此链表无环
            if(pLow == pFast)return true;//快指针追到了慢指针
            if(pFast->next != nullptr && pFast->next->next != nullptr)//快指针每次走两次next
            {
                pFast = pFast->next->next;
            }
            else
            {
                return false;
            }
            if(pLow->next != nullptr)//慢指针每次走一次next
            {
                pLow = pLow->next;
            }
            else
            {
                return false;
            }
        } while (true);
        return false;
    }
};
// @lc code=end

