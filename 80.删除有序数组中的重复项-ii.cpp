/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 2;i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 2]) nums.erase(nums.begin() + i--);
        }
        return nums.size();
    }
};
// @lc code=end

