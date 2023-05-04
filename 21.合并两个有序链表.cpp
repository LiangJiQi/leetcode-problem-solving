/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pHead = nullptr;
        ListNode* pCur = nullptr;
        while(list1 || list2)
        {
            ListNode* pNext = nullptr;
            if(list1 && !list2)pNext = list1;
            else if(!list1 && list2)pNext = list2;
            else pNext = list1->val < list2->val ? list1 : list2;

            if(pNext == list1)list1 = list1->next;
            else if(pNext == list2)list2 = list2->next;
            if(!pHead)
            {
                pHead = pNext;
                pCur = pNext;
            }
            else 
            {
                pCur->next = pNext;
                pCur = pNext;
            }
        }

        return pHead;        
    }
};
// @lc code=end

