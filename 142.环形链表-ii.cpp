/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
#include <unordered_map>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        //hash表解法
        // unordered_map<ListNode *, int> recoMap;
        // while(head)
        // {
        //     if(recoMap.count(head))return head;
        //     else recoMap[head]++;
        //     head = head->next;
        // }

        //快慢指针,设链表交点在x处，快慢指针相遇在x+y处，快指针走z步后到达交点。
        //快指针比慢指针走了两倍即2(x+y) = x+y + z + y，那么x = z
        //在快慢指针相遇后，慢指针从头再来一次，快指针不再快，而是一样一次一部，那么将在交点再次相遇
        if(!head)return head;
        auto pFast = head, pSlow = head;
        bool bMeet = false;
        while (pFast)
        {
            if(bMeet) pFast = pFast->next;
            else pFast = pFast->next ? pFast->next->next : nullptr;
            pSlow = pSlow->next;
            if(pFast == pSlow)
            {
                if(bMeet)return pFast;
                else bMeet = true;
                pSlow = head;
                if(pSlow == pFast)return head;
            }
        }
        

        return nullptr;
    }
};
// @lc code=end

