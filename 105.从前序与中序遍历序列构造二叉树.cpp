/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        //递归分割法
        TreeNode* pRoot = nullptr;//根
        // function<void(int, vector<int>, TreeNode*)> BuildTree;//递归建立
        // BuildTree = [&](int iBegin, vector<int> inOrder, TreeNode* p){
        //     if(inOrder.empty())return;//没有剩余了就返回，只是为了保平安而以
        //     p->val = preorder[iBegin];//上层保证有剩余，且已经生成好了节点
        //     auto iterPre = find(inOrder.begin(), inOrder.end(), preorder[iBegin]);//找到分割点
        //     int iLeftNum = iterPre - inOrder.begin();//分割点和起点之间的距离
        //     if(iLeftNum)//不为0则表示有左孩子
        //     {
        //         p->left = new TreeNode();
        //         BuildTree(iBegin + 1, vector(inOrder.begin(), iterPre), p->left);//建立左孩子树
        //     }
        //     if((iLeftNum + 1) != inOrder.size())//不全是左孩子树的说明有右孩子
        //     {
        //         p->right = new TreeNode();
        //         BuildTree(iBegin + iLeftNum + 1, vector(iterPre + 1, inOrder.end()), p->right);//建立右孩子树
        //     }
        // };
        // if(!inorder.empty())//非空建立树
        // {
        //     pRoot = new TreeNode();
        //     BuildTree(0, inorder, pRoot);
        // }

        //简单优化
        function<TreeNode*(int, vector<int>)> BuildTree;//递归建立
        BuildTree = [&](int iBegin, vector<int> inOrder)->TreeNode*{
            if(inOrder.empty())return nullptr;//没有剩余了就返回空
            TreeNode* p = new TreeNode(preorder[iBegin]);//生成节点
            if(!pRoot)pRoot = p;
            auto iterPre = find(inOrder.begin(), inOrder.end(), preorder[iBegin]);//找到分割点
            p->left = BuildTree(iBegin + 1, vector(inOrder.begin(), iterPre));//建立左孩子树
            p->right = BuildTree(iBegin + (iterPre - inOrder.begin()) + 1, vector(iterPre + 1, inOrder.end()));//建立右孩子树
            return p;//返回作为孩子节点
        };
        BuildTree(0, inorder);//非空建立树
        return pRoot;

    }
};
// @lc code=end

