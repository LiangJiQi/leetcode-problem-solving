/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultVec;

        function<void(TreeNode*, int)> EachFunc;
        EachFunc = [&](TreeNode* p, int iDeepCount){
            if(!p)return;
            if(resultVec.size() < iDeepCount + 1)resultVec.resize(iDeepCount + 1);
            resultVec[iDeepCount].push_back(p->val);
            EachFunc(p->left, iDeepCount + 1);
            EachFunc(p->right, iDeepCount + 1);
        };
        EachFunc(root, 0);

        return resultVec;
    }
};
// @lc code=end

