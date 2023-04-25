/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 * 前缀法和hashmap法结合，与两数之和同理
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int iResult = 0;//返回结果
        unordered_map<int, int> preSumMap;//遍历时从0到i之间的子数组之和的全部记录
        preSumMap[0] = 1;//默认空为1
        int iPreSum = 0;////遍历时从0到i之间的子数组之和
        for(int n : nums)
        {
            iPreSum += n;
            if(preSumMap.count(iPreSum - k)) iResult += preSumMap[iPreSum - k];
            preSumMap[iPreSum]++;
        }
        return iResult;
    }
};
// @lc code=end

