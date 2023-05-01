/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 * 头尾一起开始遍历，一边累积，一边计算总值
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //使用除法,不能通过有0的样例，此路不通
        int iSize = nums.size();
        // int iMuti = 1;
        // for(const int& n : nums)iMuti *= n;
        // vector<int> resultVec(iSize, iMuti);
        // for(int i = 0; i < iSize; i++)resultVec[i] = iMuti / nums[i];

        //不使用除法
        // vector<int> resultVec(iSize, 0);//答案
        // vector<int> leftVec(iSize, 0);//第i位保存的数值是0到i-1的累积值
        // int iLeftMuti = 1;//用以记录0到i的累积值
        // vector<int> rightVec(iSize, 0);//第i位保存的数值是i到nums.size()-1的累积值
        // int iRightMuti = 1;//用以记录i到nums.size()-1的累积值
        // for(int i = 0, j = iSize - 1; i < iSize && j >= 0; i++, j--)//头尾一起开始遍历
        // {
        //     leftVec[i] = iLeftMuti;//记录累积值
        //     iLeftMuti *= nums[i];
        //     rightVec[j] = iRightMuti;
        //     iRightMuti *= nums[j];
        //     if(j <= i)//如果已经遍历过了交叉点
        //     {
        //         resultVec[i] = leftVec[i] * rightVec[i];//可以计算最终值
        //         resultVec[j] = leftVec[j] * rightVec[j];
        //     }
        // }

        //方法同上，优化一下，使用常数空间
        vector<int> resultVec(iSize, 1);
        int iLeftMuti = 1;
        int iRightMuti = 1;
        for(int i = 0, j = iSize - 1; i < iSize && j >= 0; i++, j--)
        {
            resultVec[i] *= iLeftMuti;
            iLeftMuti *= nums[i];
            resultVec[j] *= iRightMuti;
            iRightMuti *= nums[j];
        }

        return resultVec;
    }
};
// @lc code=end

