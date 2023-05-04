/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
#include <functional>
using namespace std;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;

        //递归法
        // function<int(ListNode *, ListNode*)> CountFun; 
        // CountFun = [&](ListNode* pHead, ListNode* pNext)->int{
        //     if(pNext)
        //     {
        //         int iCount = CountFun(pNext, pNext->next) + 1;
        //         if(iCount == n)
        //         {
        //             if(pHead)pHead->next = pNext->next;
        //             else head = pNext->next;
        //         }
        //         return iCount;
        //     }
        //     else return 0;
        // };
        // CountFun(nullptr, head);

        //双指针
        int iCount = 1;
        ListNode* pEnd = head;
        while (iCount++ < n && pEnd)pEnd = pEnd->next; 
        if(iCount < n)return head;
        ListNode* pStart = head;
        ListNode* pPre = new ListNode(0, head);
        ListNode* pHeadPre = pPre;
        while (pEnd)
        {
            if(pEnd->next)
            {
                pEnd = pEnd->next;
                pStart = pStart->next;
                pPre = pPre->next;
            }
            else
            {
                pPre->next = pStart->next;
                break;
            }
        }
        return pHeadPre->next;
    }
};
// @lc code=end

