/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 * 两头交换法分类
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int iBegin = 0;
        int iBack = nums.size() - 1;
        for(int i = iBegin; i <= iBack; i++)
        {
            if(nums[i] == 0) swap(nums[i], nums[iBegin++]);
            if(nums[i] == 2) swap(nums[i--], nums[iBack--]);//注意从左到右遍历的，那么在进行右交换时i--不往右移，再校验右换过来的数字一次
        }
    }
};
// @lc code=end

