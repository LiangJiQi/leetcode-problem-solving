/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> resultVec;
        vector<bool> resultSetVec;
        function<void(TreeNode*, int)> DeepFunc;
        DeepFunc = [&](TreeNode* p, int iDeepCount){//深度递归，层数作参数
            if(!p)return;
            if(resultVec.size() < iDeepCount + 1)
            {
                resultSetVec.resize(iDeepCount + 1, false);
                resultVec.resize(iDeepCount + 1);
            }
            if(!resultSetVec[iDeepCount])//如果该层还没，就设置
            {
                resultSetVec[iDeepCount] = true;
                resultVec[iDeepCount] = p->val;
            }
            if(p->right)DeepFunc(p->right, iDeepCount + 1);//右孩子优先
            if(p->left)DeepFunc(p->left, iDeepCount + 1);
        };
        DeepFunc(root, 0);

        return resultVec;

    }
};
// @lc code=end

