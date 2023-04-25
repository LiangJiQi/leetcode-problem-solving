/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 * 只保留搜索特性，不要求保存平衡，可以插入不旋转。
 */

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        if(val > root->val)
        {
            if(root->right == nullptr)root->right = new TreeNode(val);//直到找到叶子节点为止
            else insertIntoBST(root->right, val);//更大就向右孩子找
        }
        else
        {
            if(root->left == nullptr) root->left = new TreeNode(val);
            else insertIntoBST(root->left, val);//更小就向左孩子找
        }
        return root;
    }
};
// @lc code=end

