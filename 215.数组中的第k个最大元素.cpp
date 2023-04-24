/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       //直接排序不能达到O(n)
       sort(nums.begin(), nums.end());
       return nums[nums.size() - k];

       //快排变种
       
    }
};
// @lc code=end

