/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = nullptr;
        ListNode* pCur = nullptr;
        int iUpAdd = 0;
        while(l1 || l2 || iUpAdd)
        {
            if(!pCur)pCur = new ListNode();
            else 
            {
                pCur->next = new ListNode();
                pCur = pCur->next;
            }
            if(!pHead)pHead = pCur;
            if(l1)
            {
                pCur->val += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                pCur->val += l2->val;
                l2 = l2->next;
            }
            pCur->val += iUpAdd;
            iUpAdd = pCur->val / 10;
            pCur->val = pCur->val % 10;
        }
        return pHead;
    }
};
// @lc code=end

