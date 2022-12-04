/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int iResult = 0;
        int iMin = prices[0];
        for(auto p : prices)
        {
            //不用担心后续数字中出现的差值会比现在的更大
            //在每一天的价格中想象之前天中的最低价格买入，此时利润为多少
            if(iMin > p)
            {
                iMin = p;
            }
            if(p - iMin > iResult)
            {
                iResult = p - iMin;
            }
        }
        return iResult;
    }
};
// @lc code=end

