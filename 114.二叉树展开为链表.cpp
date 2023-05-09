/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include <functional>
#include <stack>
using namespace std;
// @lc code=start

//Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void flatten(TreeNode* root) {

        //递归
        // TreeNode* pLast = nullptr;
        // function<void(TreeNode*)> Flatten;
        // Flatten = [&](TreeNode* p){
        //     if(!p)return;
        //     Flatten(p->right);
        //     Flatten(p->left);
        //     p->right = pLast;
        //     p->left = nullptr;
        //     pLast = p;
        // };
        // Flatten(root);

        //遍历 mirro法
        stack<TreeNode*>headRoot;
        while (root || !headRoot.empty())
        {
            while(root)//优先处理左孩子树
            {
                headRoot.push(root);
                root = root->left;
            }
            root = headRoot.top();
            headRoot.pop();
            if(root->left)//如果当前节点有左孩子
            {
                auto pLeft = root->left;
                while(pLeft->right) pLeft = pLeft->right;//找到左孩子的最右叶子节点
                if(pLeft->right != root->right || !root->right)
                {
                    pLeft->right = root->right;//将左孩子的最右叶子节点链接到右孩子上
                    root->right = root->left;//将右孩子设为左孩子
                    root->left = nullptr;//左孩子置空
                    root = root->right;//重新处理右孩子（的右孩子，下方还有一个right，因为此时原本的left已经插入到了root和right之间了）
                }
            }
            root = root->right;//处理右孩子
        }
        
    }
};
// @lc code=end

