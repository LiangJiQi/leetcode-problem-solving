/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
#include <vector>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    vector<vector<int>> resultVec;
    void ReOrder(TreeNode *node, int iCout)
    {
        if(!node)return;//校验保平安
        if(resultVec.size() < iCout + 1)resultVec.resize(iCout + 1);//长度不够的补齐
        if(!(iCout % 2))resultVec[iCout].push_back(node->val);//iCout从0开始，偶数时左到右插入
        else resultVec[iCout].insert(resultVec[iCout].begin(), node->val);//奇数时右到左插入
        ReOrder(node->left, iCout + 1);//左孩子优先递归
        ReOrder(node->right, iCout + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ReOrder(root, 0);
        return resultVec;
    }
};
// @lc code=end

