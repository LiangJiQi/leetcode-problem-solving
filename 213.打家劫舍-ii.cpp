/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:

    int RobNoCircle(vector<int>& nums)
    {
        int iSize = nums.size();
        vector<int>dp(iSize);
        if(iSize == 0)return 0;
        dp[0] = nums[0];
        if(iSize == 1)return dp[0];
        dp[1] = max(dp[0], nums[1]);
        if(iSize == 2)return dp[1];

        int iMaxRob = dp[1];
        for(int i = 2; i < iSize; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            iMaxRob = max(iMaxRob, dp[i]);
        }
        return iMaxRob;
    }

    int rob(vector<int>& nums) {
        /*
        分情况处理，简化为198.打家劫舍I的问题
        1.既不抢头，也不抢尾
        2.抢头，但不抢尾
        3.不抢头，抢尾
        对每种情况使用198.打家劫舍I的问题解决
        */        
        int iSize = nums.size();
        if(iSize == 0)return 0;
        if(iSize == 1)return nums[0];
        if(iSize == 2)return max(nums[0], nums[1]);

        int iMaxRob = 0;
        vector<int>numsCopy[3];
        //1.既不抢头，也不抢尾
        numsCopy[0].resize(iSize - 2);
        std::copy(++nums.begin(), --nums.end(), numsCopy[0].begin());
        //2.抢头，但不抢尾
        numsCopy[1].resize(iSize - 1);
        std::copy(nums.begin(), --nums.end(), numsCopy[1].begin());
        //3.不抢头，抢尾
        numsCopy[2].resize(iSize - 1);
        std::copy(++nums.begin(), nums.end(), numsCopy[2].begin());
        //取三种情况的最大值
        for(auto c : numsCopy)
        {
            iMaxRob = max(iMaxRob, RobNoCircle(c));
        }
        return iMaxRob;
    }
};
// @lc code=end

