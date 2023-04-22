/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {

        int iSize = nums.size();
        vector<int>dp(iSize);//dp[i]代表着从0到i能打劫到的最高金额数
        //长度太短直接选择返回
        if(iSize == 0)return 0;
        dp[0] = nums[0];
        if(iSize == 1)return dp[0];
        dp[1] = max(dp[0], nums[1]);
        //遍历取最高的dp[i]
        int iMaxRob = dp[1];
        for(int i = 2;i < iSize; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            iMaxRob = max(iMaxRob, dp[i]);
        }
        return iMaxRob;
    }
};
// @lc code=end

