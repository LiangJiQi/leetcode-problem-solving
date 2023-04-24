/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 * 动态规划出现递增时计算以往的加上递增后的最高数为当前数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //时间复杂度O(n^2/2) = O(n^2)
        int iResult = 0;
        vector<int>maxCount(nums.size(), 1);//初始化每一个数算作1长度，maxCount[i]代表算上在i上的数后从0到i的最长递增自序列的长度
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j >= 0; j--)
            {
                if(nums[i] > nums[j])//如果出现递增
                {
                    maxCount[i] = max(maxCount[i], 1 + maxCount[j]);//看以往的递增中加1后哪个最高保留为当前。
                }
            }
            iResult = max(maxCount[i], iResult);
        }

        return iResult;
    }
};
// @lc code=end

