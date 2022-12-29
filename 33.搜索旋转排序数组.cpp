/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //变种二分法搜索
        int iHead = 0;
        int iBack = nums.size() - 1;
        int iMid = (iHead + iBack) / 2;
        while (iHead <= iBack)
        {
            iMid = (iHead + iBack) / 2;
            if(nums[iMid] == target)//中间值命中直接返回下标
            {
                return iMid;
            }
            else if (nums[iMid] < target)//中间值比目标值小
            {
                //只有一种情况去左边查找，左边乱序，且目标值完全不在右边
                if(nums[iHead] > nums[iMid] && nums[iMid] <= nums[iBack] && target > nums[iBack])
                {
                    iBack = iMid - 1;
                }
                else
                {
                    iHead = iMid + 1;
                }
            }
            else //中间值比目标值大
            {
                //只有一种情况去右边找，右边乱序，且目标值完全不再左边
                if(nums[iBack] < nums[iMid] && nums[iMid] >= nums[iHead] && target < nums[iHead])
                {
                    iHead = iMid + 1;
                }
                else
                {
                    iBack = iMid - 1;
                }
            }
            
        }
        return -1;
    }
};
// @lc code=end

