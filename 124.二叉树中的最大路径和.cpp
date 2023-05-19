/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
#include <functional>
#include <limits.h>
using namespace std;
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
    int maxPathSum(TreeNode* root) {
        //递归法
        int iResult = INT_MIN;//答案
        function<int(TreeNode* p)>SumCheckFunc;//递归函数
        SumCheckFunc = [&](TreeNode* p)->int{
            if(!p)return 0;//判空保平安
            int iLeft = SumCheckFunc(p->left);//左子树的最大长度
            int iRight = SumCheckFunc(p->right);//右子树的最大长度
            //求左右孩子带上根节点后的最大路径
            int iMax = max(p->left ? iLeft : INT_MIN, p->val);//左比较
            iMax = max(p->right ? iRight : INT_MIN, iMax);//右比较
            iMax = max(p->val + iLeft, iMax);//左加根比较
            iMax = max(p->val + iRight, iMax);//右加根比较
            iMax = max(p->val + iLeft + iRight, iMax);//左加根加右比较
            iResult = max(iMax, iResult);//得出最长的路径值
            return max(max(iLeft + p->val, iRight + p->val), p->val);//返回最大路径，要么加左右孩子，要么不加
        };
        SumCheckFunc(root);//递归求解
        return iResult;
    }
};
// @lc code=end

