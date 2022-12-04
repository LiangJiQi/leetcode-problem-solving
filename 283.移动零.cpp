/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty())return;
        //常规解法
        // for(int i = 0;i < nums.size();i++)
        // {
        //     if(nums[i] == 0)
        //     {
        //         for(int j = i + 1;j < nums.size();j++)
        //         {
        //             if(nums[j] != 0)
        //             {
        //                 nums[i] = nums[j];
        //                 nums[j] = 0;
        //                 break;
        //             }
        //         }
        //     }
        // }
        //前后双下标遍历
        for(int i = 0, j = 0;i < nums.size() && j < nums.size();)
        {
            if(nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }

    }
};
// @lc code=end

