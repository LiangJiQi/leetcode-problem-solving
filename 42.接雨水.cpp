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
        vector<int> singleStack;//单调递减栈
        int iSumTrap = 0;//总数
        for(int n = 0; n < height.size(); n++)
        {
            if(!singleStack.empty() && height[n] > singleStack.back())//如果栈非空，且当前遍历的数大于栈顶元素
            {
                int iMinLen = min(singleStack[0], height[n]);//取小值，因为能接到的雨水量取决于最小值
                for(int i = singleStack.size() - 1; i >= 0; i--)//从栈顶开始计算
                {
                    if(singleStack[i] > iMinLen)break;//如果有更大值就停止计算
                    iSumTrap += iMinLen - singleStack[i];//累计
                    singleStack[i] = iMinLen;//并且将累计过的值抹去，防止以后的计算中重复累计
                    if(singleStack[i] == singleStack[0])singleStack.erase(singleStack.begin() + i);//如果恰巧是单调栈的底部（最大值）相同则可以出栈，避免重复遍历计算0
                }
            }
            singleStack.push_back(height[n]);//入栈
        }
        return iSumTrap;
        
    }
};
// @lc code=end

