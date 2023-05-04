/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node *pHead = head;
        int iCount = 0;//计数
        unordered_map<Node*, int> randomMap;//保存每个旧节点对应的下标
        vector<Node*>newNodeVec;//保存每个新节点
        Node* pNewHead = new Node(pHead->val);//保存头节点
        Node* pCur = pNewHead;//遍历新节点的当前节点
        newNodeVec.push_back(pCur);
        randomMap[pHead] = iCount;
        while (pHead->next)//遍历一遍
        {
            pHead = pHead->next;
            pCur->next = new Node(pHead->val);//生成新节点
            pCur = pCur->next;
            newNodeVec.push_back(pCur);//记录新节点
            randomMap[pHead] = ++iCount;//记录旧节点的位置
        }
        pCur = pNewHead;//重新遍历一遍
        while (head)
        {
            //在新节点上复制旧节点的随机数据
            if(head->random)pCur->random = newNodeVec[randomMap[head->random]];
            else pCur->random = nullptr;
            head = head->next;
            pCur = pCur->next;
        }
        
        return  pNewHead;
    }
};
// @lc code=end

