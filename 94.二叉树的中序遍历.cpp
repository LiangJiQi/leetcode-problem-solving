/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resultVec;
        
        //递归法
        function<void(TreeNode*)> deepTra;
        deepTra = [&](TreeNode  * node)->void{
            if(!node)return;
            if(node->left)deepTra(node->left);
            resultVec.push_back(node->val);
            if(node->right)deepTra(node->right);
        };
        deepTra(root);

        //迭代法
        //morris
        // TreeNode* pPre = nullptr;
        // while(root)
        // {
        //     if(root->left)
        //     {
        //         pPre = root->left;
        //         while (pPre)
        //         {
        //             if(pPre->right == root)
        //             {
        //                 resultVec.push_back(root->val);
        //                 root = root->right;
        //                 break;
        //             }
        //             else if(pPre->right) pPre = pPre->right;
        //             else break;
        //         }
        //         if(!root)break;
        //         if(pPre->right != root)
        //         {
        //             pPre->right = root;
        //             root = root->left;
        //         }
        //     }
        //     else
        //     {
        //         resultVec.push_back(root->val);
        //         root = root->right;
        //     }
        // }

        // return resultVec;
    }
};
// @lc code=end

