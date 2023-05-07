/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        // if(!root)return 0;
        // if(root->left && !root->right)return maxDepth(root->left) + 1;
        // else if(!root->left && root->right)return maxDepth(root->right) + 1;
        // else if(root->left && root->right)
        // {
        //     int iLeft = maxDepth(root->left) + 1;
        //     int iRight = maxDepth(root->right) + 1;
        //     return iLeft > iRight ? iLeft : iRight;
        // }
        // else return 1;

        return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};
// @lc code=end

