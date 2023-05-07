/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include <functional>
#include <limits.h>
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
    bool isValidBST(TreeNode* root) {

        //递归检查子树的范围
        // function<bool(TreeNode*, long long int, long long int)> CheckFun;
        // CheckFun = [&](TreeNode* p, long long int iMaxNum, long long int iMinNum){
        //     if(!p)return true;
        //     if(p->val >= iMaxNum || p->val <= iMinNum)return false;
        //     bool bLeft = CheckFun(p->left, p->val, iMinNum);
        //     bool bRight = CheckFun(p->right, iMaxNum, p->val);
        //     return bLeft && bRight;
        // };
        // return CheckFun(root, LONG_MAX, LONG_MIN);

        //中序遍历的结果是否是增序的
        long long int iMidNum = LONG_MIN;
        stack<TreeNode*>midRootStack;
        while(!midRootStack.empty() || root)
        {
            while (root)
            {
                midRootStack.push(root);
                root = root->left;//左孩子在前
            }
            root = midRootStack.top();
            midRootStack.pop();
            if(iMidNum >= root->val) return false;//如果不是升序的则不算搜索树
            iMidNum = root->val;
            root = root->right;//右孩子在后
        }
        return true;
    }
};
// @lc code=end

