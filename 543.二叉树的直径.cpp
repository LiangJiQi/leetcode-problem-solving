/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include <functional>
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
    int diameterOfBinaryTree(TreeNode* root) {
        int iResult = 0;//答案
        function<int(TreeNode*)> CountFun;
        CountFun = [&](TreeNode* p)->int{
            if(!p)return 0;//叶子节点回0
            int iLeft = CountFun(p->left);//左孩子深度
            int iRight = CountFun(p->right);//右孩子深度
            iResult = max(iResult, iLeft + iRight);//左右孩子深度之和的最高值
            return max(iLeft, iRight) + 1;//每次递归深度加一
        };
        CountFun(root);
        return iResult;
    }
};
// @lc code=end

