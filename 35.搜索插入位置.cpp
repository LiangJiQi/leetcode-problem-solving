/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int iBegin = 0;
        int iEnd = nums.size() - 1;
        int iMid = (iBegin + iEnd) / 2;
        while(iBegin <= iEnd)//二分查找
        {
            iMid = (iBegin + iEnd) / 2;
            if(nums[iMid] == target)return iMid;
            else if(nums[iMid] < target)iBegin = iMid + 1;
            else iEnd = iMid - 1;
        }
        return iBegin;//找不到的插入位置
    }
};
// @lc code=end

