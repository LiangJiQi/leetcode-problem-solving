/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int iNumSize = nums.size();
        int iMaxSum = 0;
        int iSubSum = iNumSize ? nums[0] : 0;
        for(int i = 0, j = 0;i < iNumSize && j <= i;)
        {
            if(i == j)
            {
                iSubSum += (++i < iNumSize) ? nums[i] : 0;
                iMaxSum = iSubSum > iMaxSum ? iSubSum : iMaxSum;
                continue;
            }
            int iLeft = iSubSum - ((j+i)<iNumSize ? nums[j] : 0);
            int iRight = iSubSum + ((i+i)<iNumSize ? nums[i] : 0); 
            if (iLeft > iRight)
            {
                j++;
                iSubSum = iLeft;
            }
            else if(iLeft < iRight)
            {
                i++;
                iSubSum = iRight;
            }
            else
            {
                
            }
        }

        return iMaxSum;
    }
};
// @lc code=end

