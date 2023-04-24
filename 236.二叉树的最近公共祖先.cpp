/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 * 深度递归查找到对应的节点后返回true，两个true第一次相遇时即为最近公共祖先所在节点
 */
// @lc code=start

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    TreeNode *pFather;//公共祖先节点
    bool FindNode(TreeNode * node, TreeNode *p, TreeNode *q)
    {
        bool bFind = false;
        if(!node || pFather)return bFind;//当前非null且没找到才能继续找
        if(node == p || node == q)bFind = true;//当前节点找到了
        bool bFindLeft = FindNode(node->left, p, q);//向左孩子继续递归找
        bool bFindRight = FindNode(node->right, p, q);//向右孩子继续递归找
        if(((bFind && bFindLeft) || (bFind && bFindRight) || (bFindLeft && bFindRight)) && !pFather)//当两个true相遇且没找到时
        {
            pFather = node;//找到
        }
        return bFindLeft || bFindRight || bFind;//无论是当前还是左孩子与右孩子找到了反馈给上一层调用
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pFather = nullptr;
        FindNode(root, p, q);//深度优先递归
        return pFather;
    }
};
// @lc code=end

