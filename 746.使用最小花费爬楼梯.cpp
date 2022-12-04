/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include<vector>
using namespace std;

//题解：动态规划法，因为每次可走一节或两节，那么走到第三节楼梯时使用的最小花费为
//<走到第一节楼梯使用的最小花费加上第一节楼梯的花费>和
//<走到第二节楼梯使用的最小花费加上第二节楼梯的花费>之中的最小值，即可走到第三节楼梯
//同理，走到第n节楼梯，所使用的花费即是<走到第n-1的最小花费加上n-1处的花费>和
//<走到n-2的最小花费加上n-2处的花费>中的最小值，即可使用最小花费到达第n节楼梯。
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1)return cost[0];
        if(cost.size() == 2)return cost[0] > cost[1] ? cost[1] : cost[0];
        int iResult = 0;
        int preMinCost[2] = {cost[0], cost[1]};
        for(int i = 2;i <= cost.size();i++)
        {
            iResult = min(preMinCost[0], preMinCost[1]);
            if(i >= cost.size())break;
            preMinCost[0] = preMinCost[1];
            preMinCost[1] = iResult + cost[i];
        }
        return iResult;
    }
};
// @lc code=end

