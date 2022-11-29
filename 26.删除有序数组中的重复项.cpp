/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
//题解：先排序，后遍历删除


#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int iResult = 0;
        //库函数排序
        // sort(nums.begin(),nums.end());
        //冒泡排序
        // for(int i = 0;i < nums.size();i++)
        // {
        //     for(int j = i;j < nums.size();j++)
        //     {

        //     }
        // }

        //仅计算不同项数量
        // for(int i = 0, j = i+1;j < nums.size();j++)
        // {
        //     if(i != j && nums[i] != nums[j])
        //     {
        //         i = j;
        //         iResult++;
        //     }
        // }

        //删除重复项
        for(int i = 0;i < nums.size();i++)
        {
            for(int j = i+1;j < nums.size();j++)
            {
                if(nums[i] == nums[j])
                {
                    nums.erase(nums.begin() + j);
                }
            }
            iResult++;
        }
        nums.resize(iResult);
        return iResult;
    }
};
// @lc code=end

