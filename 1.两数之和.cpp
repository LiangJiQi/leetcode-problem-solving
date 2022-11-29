/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result(2,0);
        //前缀法
        unordered_map<int, int>preNumMap;
        int iIndex = 0;
        for(auto i : nums)
        {
            if (preNumMap.count(i))
            {
                result[0] = preNumMap[target - i];
                result[1] = iIndex;
                return result;
            }
            else
            {
                preNumMap[target - i] = iIndex;
            }
            iIndex++;
        }
        return result;
    }
};
// @lc code=end

