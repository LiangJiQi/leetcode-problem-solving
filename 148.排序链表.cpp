/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <set>
using namespace std;
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
    ListNode* sortList(ListNode* head) {

        if(!head || !head->next)return head;
        auto CompFun = [](const ListNode* a,const ListNode* b){
            return a->val < b->val;
        };//排序函数
        multiset<ListNode*, decltype(CompFun)> sortList(CompFun);//保存所有节点并排序
        while(head)
        {
            sortList.insert(head);
            head = head->next;
        }
        //对排好序的节点重新链接
        for(auto iter = sortList.begin(), next = ++sortList.begin(); iter != sortList.end(); next++, iter++)
        {
            if(next != sortList.end())(*iter)->next = *next;
            else (*iter)->next = nullptr;
        }
        return *sortList.begin();

        //归并排序
        // auto Merge = [](){};

        // int iLenght = 0;
        // auto pCur = head;
        // while(pCur)
        // {
        //     iLenght++;
        //     pCur = pCur->next;
        // }
        // int iMerge = 1;
        // while (iMerge < iLenght)
        // {
            
        // }
        
    }
};
// @lc code=end

