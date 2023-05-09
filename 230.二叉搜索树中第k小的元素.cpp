/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */
#include <vector>
#include <functional>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        //中序遍历得到升序结果
        vector<int> midRootVec;
        //递归法
        function<void(TreeNode*)> DeepFunc;
        DeepFunc = [&](TreeNode *p){
            if(!p || midRootVec.size() >= k)return;
            if(p->left)DeepFunc(p->left);
            if(midRootVec.size() < k)midRootVec.push_back(p->val);
            if(p->right)DeepFunc(p->right);
        };
        DeepFunc(root);

        //遍历法
        // stack<TreeNode*>midRootStack;
        // while ((!midRootStack.empty() || root) && midRootVec.size() < k)
        // {
        //     while (root)
        //     {
        //         midRootStack.push(root);
        //         root = root->left;
        //     }
        //     root = midRootStack.top();
        //     midRootStack.pop();
        //     midRootVec.push_back(root->val);
        //     root = root->right;
        // }

        if(midRootVec.size() >= k)return midRootVec.back();

        return 0;
    }
};
// @lc code=end

