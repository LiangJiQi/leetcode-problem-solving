/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return nullptr;//判空保平安
        int iCount = 1;//累计数
        ListNode *pCur = head;
        while (pCur->next)
        {
            if(iCount == k)break;//累计到k则算一组
            iCount++;//累计数
            pCur = pCur->next;//移到下一个
        }
        
        if(iCount < k) return head;//不足k个不用翻转了，直接返回剩余的head
        pCur = reverseKGroup(pCur->next, k);//如果够k则继续
        //开始翻转k组内节点
        ListNode *pNext = nullptr;//head的下一个节点
        while(true)
        {
            pNext = head->next;//记录
            head->next = pCur;//头节点的下一节点接到翻转过的链表头节点
            pCur = head;//记录翻转过的链表头节点
            if(!(--iCount))break;//足够k了就结束
            head = pNext;//记录未翻转的链表头节点
        }
        return head;
    }
};
// @lc code=end

