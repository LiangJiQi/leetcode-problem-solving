/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <functional>
#include <queue>
using namespace std;
// @lc code=start

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        //递归法
        function<bool(TreeNode*, TreeNode*)> Check;//
        Check = [&](TreeNode* p, TreeNode *q)->bool{//同步镜像移动的两个指针
            if(!p || !q)
            {
                if(!q && !p)return true;
                return false;
            }
            if(p->val != q->val)return false;//如果两个指针不同则false
            return Check(p->left, q->right) && Check(p->right, q->left);//同步镜像移动
        };
        return Check(root, root);

        //迭代法
        // queue<TreeNode*> nodeQueue;//遍历队列
        // nodeQueue.push(root);//保证从头开始
        // nodeQueue.push(root);
        // TreeNode* p = nullptr;
        // TreeNode* q = nullptr;
        // while (!nodeQueue.empty())
        // {
        //     p = nodeQueue.front();//同时出列比较
        //     nodeQueue.pop(); 
        //     q = nodeQueue.front();
        //     nodeQueue.pop();
        //     if((p && !q) || (!p && q))return false;//其中有一个为空则不相等
        //     if(!p && !q)continue;
        //     if(p->val != q->val)return false;//比较
        //     nodeQueue.push(p->left);//镜像入列
        //     nodeQueue.push(q->right);
        //     nodeQueue.push(p->right);
        //     nodeQueue.push(q->left);
        // }
        // return true;
    }
};
// @lc code=end

