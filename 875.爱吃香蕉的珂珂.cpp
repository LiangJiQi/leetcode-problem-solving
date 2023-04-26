/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 * 确认速度的边界之后采用二分法逼近正确速度
 */
#include <vector>
#include <math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int iMax = 0;
        for(int n : piles)//计算速度的上界
        {
            iMax = max(n, iMax);
        }
        int iMin = 1;//速度下界默认为1
        int iMid = (iMax + iMin) / 2;
        while(iMin <= iMax)
        {
            iMid = (iMax + iMin) / 2;//二分查找
            int iMidHour = 0;
            for(int n : piles) iMidHour += ceil((double)((double)n / (double)iMid));//当前中间速度是否满足
            if(iMidHour == h)
            {
                if(iMax == iMid)break;//无法继续往下找了就结束
                iMax = iMid;//如果满足继续向下找，因为题目要求最小速度
            }
            else if(iMidHour > h)//速度太小了就向上找
            {
                if(iMin < iMid) iMin = iMid;//这是为了正确逼近相差较大的总数和用时
                else iMin = iMid + 1;
            }
            else
            {
                if(iMax > iMid) iMax = iMid;//这是为了正确逼近相差较大的总数和用时
                else iMax = iMid - 1;
            }
        }

        return iMid;
    }
};
// @lc code=end

