/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 * 保存一个单调栈，里面的数总是递减的，入栈时，如果大于栈顶数，则作一次计算出栈。
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int iSumTrap = 0;//总数

        //单调栈法
        // vector<int> singleStack;//单调递减栈
        // for(int n = 0; n < height.size(); n++)
        // {
        //     if(!singleStack.empty() && height[n] > singleStack.back())//如果栈非空，且当前遍历的数大于栈顶元素
        //     {
        //         int iMinLen = min(singleStack[0], height[n]);//取小值，因为能接到的雨水量取决于最小值
        //         for(int i = singleStack.size() - 1; i >= 0; i--)//从栈顶开始计算
        //         {
        //             if(singleStack[i] > iMinLen)break;//如果有更大值就停止计算
        //             iSumTrap += iMinLen - singleStack[i];//累计
        //             singleStack[i] = iMinLen;//并且将累计过的值抹去，防止以后的计算中重复累计
        //             if(singleStack[i] == singleStack[0])singleStack.erase(singleStack.begin() + i);//如果恰巧是单调栈的底部（最大值）相同则可以出栈，避免重复遍历计算0
        //         }
        //     }
        //     singleStack.push_back(height[n]);//入栈
        // }


        //双指针法
        //拆成左右两部份分别计算，会在最高值处相遇，计算两边时视有一条边界在最高处
        // if(height.empty())return iSumTrap;
        // int iLeftIndex = 0;////遍历时左往右下标
        // int iRightIndex = height.size() - 1;//遍历时右往左下标
        // int iLeftMax = height[iLeftIndex];//遍历时左往右最大值
        // int iRightMax = height[iRightIndex];//遍历时右往左最大值
        // while (iLeftIndex < iRightIndex)//直到两个相遇
        // {
        //     if(height[iLeftIndex] < height[iRightIndex])//当左高低于右高时 计算左边
        //     {
        //         iSumTrap +=  iLeftMax - height[iLeftIndex++];//但累计的是左最高到当前高
        //         iLeftMax = max(iLeftMax, height[iLeftIndex]);
        //     }
        //     else//当右高比左高小时计算右边
        //     {
        //         iSumTrap += iRightMax - height[iRightIndex--];
        //         iRightMax = max(iRightMax, height[iRightIndex]);
        //     }
        // }
        
        //动态规划法
        //两部份分别计算，计算两边时视另一边的边界为无穷高，取叠加重合处就是真实值
        if(height.empty())return iSumTrap;
        vector<int>leftHeight(height.size(), 0);//从左到右，单调满增
        vector<int>rightHeight(height.size(), 0);//从右到左，单调满增
        int iMaxLeft = 0;//遍历时左往右最大值
        int iMaxRight = 0;//遍历时右往左最大值
        for(int i = 0, j = height.size() - 1; i < height.size() && j >=0; i++, j--)
        {
            iMaxLeft = max(iMaxLeft, height[i]);
            leftHeight[i] = iMaxLeft;//填满
            iMaxRight = max(iMaxRight, height[j]);
            rightHeight[j] = iMaxRight;//填满
            
        }
        for(int i = 0; i < height.size(); i++)
        {
            iSumTrap += min(leftHeight[i], rightHeight[i]) - height[i];//两个的重合区域减去实际高度就为可蓄值
        }

        return iSumTrap;
        
    }
};
// @lc code=end

