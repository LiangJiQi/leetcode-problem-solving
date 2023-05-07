/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        TreeNode* root = new TreeNode();//根
        function<void(TreeNode*, int, int)> BuildFunc;//建造函数
        BuildFunc = [&](TreeNode* p, int iBegin, int iEnd){
            if(iBegin > iEnd)return;//没有数剩余了不可建造
            int iMid = (iBegin + iEnd) / 2;
            p->val = nums[iMid];//取剩余数中间数作根节点
            if(iBegin <= iMid - 1)//去掉中间数后左边还剩
            {
                p->left = new TreeNode();//生成左子树的根节点
                BuildFunc(p->left, iBegin, iMid - 1);//建造左子树
            }
            if(iMid + 1 <= iEnd)//右边同理
            {
                p->right = new TreeNode();
                BuildFunc(p->right, iMid + 1, iEnd);
            }
        };
        BuildFunc(root, 0, nums.size() - 1);
        return root;
    }
};
// @lc code=end

