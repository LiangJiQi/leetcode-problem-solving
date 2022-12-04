/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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

//题解：利用原理A + B = B + A,双指针，a指针当从A头走到A尾后下一步从B头开始走，同理，b指针从B头走到B尾后
//从A头开始走，如果存在相交点，那么双指针a和b会在相交点走过一样的路程长度，即a和b首次指向相同的节点时即为相交点


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        auto pListA = headA;
        auto pListB = headB;
        bool bChangeA = false, bChangeB = false;//是否掉头走过了
        do
        {
            if(pListA == pListB)return pListA;//首次指向相同节点即为相交点
            if(pListA->next == nullptr)
            {
                if(!bChangeA)//没有掉头走过，掉一次头
                {
                    pListA = headB;
                    bChangeA = true;
                }
                else
                {
                    return nullptr;
                }
            }
            else
            {
                pListA = pListA->next;
            }
            if(pListB->next == nullptr)
            {
                if(!bChangeB)//没有掉头走过，掉头一次
                {
                    pListB = headA;
                    bChangeB = true;
                }
                else
                {
                    return nullptr;
                }
            }
            else
            {
                pListB = pListB->next;
            }
        } while (true);
        return nullptr;
    }
};
// @lc code=end

