/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */
#include <functional>
#include <unordered_map>
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
    int pathSum(TreeNode* root, int targetSum) {
        
        //递归前缀和法
        int iCount = 0;//答案计数
        unordered_map<long long int, int> sumMap;//key：根节点到每一个节点的和，value:这些和出现的重复次数
        sumMap[0] = 1;//有0保证单个节点的值作为前缀和
        function<void(TreeNode*, long long int)> CountFun;//递归函数
        CountFun = [&](TreeNode* p, long long int iSumNum){
            if(!p)return;
            iSumNum += p->val;//累加前缀和
            //这里的iSumNum - targetSum表示前面的累计和中有没有距离当前节点刚好targetSum的前缀
            if(sumMap.count((long long int)((long long int)iSumNum - (long long int)targetSum)))iCount += sumMap[(long long int)((long long int)iSumNum - (long long int)targetSum)];//增加次数
            sumMap[iSumNum]++;//记录前缀
            CountFun(p->left, iSumNum);
            CountFun(p->right, iSumNum);
            sumMap[iSumNum]--;//递归返回后，删减前缀
        };
        CountFun(root, 0);

        return iCount;

    }
};
// @lc code=end

