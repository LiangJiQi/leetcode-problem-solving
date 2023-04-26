/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */
#include <vector>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;//保存答案头节点
        if(lists.empty())return head;
        ListNode* tail = nullptr;//答案的尾节点
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>sortQueue;//最小优先队列
        int i = 0;//遍历数组当前所有头节点
        int iSize = lists.size();//数组中还剩多少个头节点非空的
        while(true)
        {
            if(sortQueue.size() < iSize)//优先队列里还没填充满
            {
                if(lists[i])sortQueue.push(make_pair(lists[i]->val, i));//将数组内头节点填充进优先队列
                else iSize--;//如果已经就是空的了，将剩余数减少
            }
            else if(sortQueue.size() == iSize)//填充满了之后
            {
                i = sortQueue.top().second;//取最小数所在数组中的下标
                sortQueue.pop();//出列
                if(!head)//记录头节点
                {
                    head = lists[i];
                    tail = lists[i];
                }
                else//插入尾节点后面
                {
                    tail->next = lists[i];
                    tail = tail->next;
                }
                lists[i] = lists[i]->next;//替换该下标位置的头节点为下一个
                if(lists[i])sortQueue.push(make_pair(lists[i]->val, i));//新入列排序
                else iSize--;//为空没有了就减少剩余数
            }
            if(i +1 < lists.size())i++;//遍历数组内所有头节点
            else i = 0;//重复遍历，防止中间有空的
            if(iSize <= 0)break;//如果已经没有剩余了
        }

        return head;
    }
};
// @lc code=end

