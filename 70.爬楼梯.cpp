/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:

    //递归求解，时间超限，when testcase = 44,time limit exceeded
    int iResult;
    void back(const int iRemainder, const int iStepNum)
    {
        if(iRemainder - iStepNum == 0)
        {
            iResult++;
        }
        else if(iRemainder - iStepNum < 0)
        {
            return;
        }
        else if(iRemainder - iStepNum > 0)
        {
            back(iRemainder - iStepNum, 1);
            back(iRemainder - iStepNum, 2);
        }
    }

    int climbStairs(int n) {
        iResult = 0;
        // back(n, 1);
        // back(n, 2);

        //动态规划法
        //n = 1时仅有一种走法
        //n = 2时有两种走法：【1,1】、【2】
        //n = 3时实际上是第一阶楼梯和第二阶楼梯走上去的，因为只有1步或者2步可选
        //那么n = 3时的走法数量是n = 1和n = 2的走法数量相加总数(斐波那契数列)
        //同理n阶楼梯的走法数量就是n-1和n-2数量相加总数
        int pre[2] = {0, 0};
        if(n == 1)
        {
            iResult = 1;
        }
        else if(n == 2)
        {
            iResult = 2;
        }
        else if(n > 2)
        {
            pre[0] = 1;
            pre[1] = 2;
        }
        for (int i = 3; i <= n; i++)
        {
            iResult = pre[0] + pre[1];
            pre[0] = pre[1];
            pre[1] = iResult;
        }
        return iResult;
    }
};
// @lc code=end

