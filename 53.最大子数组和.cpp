/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 * 动态规划法求解，当前数大于从头到当前之间的累积和时放弃以往的累积和，从新开始算累积和
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int iNumSize = nums.size();
        int iSubSum = 0;
        int iMaxSum = iNumSize ? nums[0] : 0;//初始化为第一个数
        for(int i = 0;i < iNumSize ; i++)
        {
            if(nums[i] > iSubSum + nums[i])//当前数大于从头到当前之间的累积和时放弃以往的累积和
            {
                iSubSum = nums[i];
            }
            else
            {
                iSubSum += nums[i];//从新开始算累积和
            }
            iMaxSum = max(iMaxSum, iSubSum);//每次累积和都相互比较，取最大数作结果
        }
        return iMaxSum;
    }
};
// @lc code=end

