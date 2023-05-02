/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include <vector>
#include <functional>
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
    bool isPalindrome(ListNode* head) {

        //普通拷贝比较
        // vector<int>nums;
        // while(head)
        // {
        //     nums.push_back(head->val);
        //     head = head->next;
        // }
        // for(int i = 0; i < nums.size() / 2; i++)
        // {
        //     if(nums[i] != nums[nums.size() - i - 1])return false;
        // }
        // return true;

        //递归比较
        std::function<bool(ListNode*)> check= [&](ListNode * p){
            if(p)
            {
                if(!check(p->next)) return false;
                else if(p->val != head->val) return false;
                head = head->next;
            }
            return true;
        };
        auto pFront = head;
        return check(pFront);
    }
};
// @lc code=end

