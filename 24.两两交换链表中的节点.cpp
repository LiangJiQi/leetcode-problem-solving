/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        
        //迭代法
        if(!head)return head;
        ListNode* pHeadPre = new ListNode(0, head);//预留头节点
        ListNode* pPre = pHeadPre;//前指针
        ListNode* pNext = head->next;//后指针
        int iCount = 2;
        while(pNext)
        {
            if(iCount == 2)//如果够2则为一组
            {
                //翻转
                head->next = pNext->next;
                pNext->next = head;
                pPre->next = pNext;//和上一组的末尾链上
                //重新设置为正确的位置
                head = pPre->next;
                pNext = pNext->next;
                iCount = 0;
            }
            else//不够就继续移动
            {
                head = head->next;
                pNext = pNext->next;
                pPre = pPre->next;
                iCount++;
            }
        }
        return pHeadPre->next;

        //递归法
        // int iCount = 0;
        // auto pCur = head;//计2个为一组
        // while(iCount < 2 && pCur)
        // {
        //     pCur = pCur->next;
        //     iCount++;
        // }
        // if(iCount < 2)return head;//不够就不交换
        // pCur = swapPairs(pCur);//够则先递归
        // auto pNext = head->next;//递归结束了，后续的节点已经交换了，返回的是头节点
        // pNext->next = head;//交换
        // head->next = pCur;//交换
        // return pNext;//返回头节点

    }
};
// @lc code=end

