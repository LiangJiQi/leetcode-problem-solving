/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 * 要求只遍历一遍O(n)，使用两个map存下所有连续序列的头和尾的数，遍历每个数时如果能增加自序列长度则添加进保存最后得最长长度。
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int iMaxLength = 0;
        unordered_map<int, int>firstMap;//所有连续子序列的头和尾数
        unordered_map<int, int>backMap;//所有连续子序列的尾和头数
        for(auto i : nums)
        {
            if(backMap.count(i - 1) && firstMap.count(i + 1))//如果当前遍历的数可以将两个连续子序列合并
            {
                firstMap[backMap[i - 1]] = firstMap[i + 1];//新的连续子序列区间
                backMap[firstMap[i + 1]] = backMap[i - 1];//新的连续子序列区间
                iMaxLength = max(iMaxLength, firstMap[i + 1] - backMap[i - 1] + 1);//看一下长度
                backMap.erase(i - 1);//删掉旧的区间
                firstMap.erase(i + 1);
            }
            else if(backMap.count(i) || firstMap.count(i)) continue;//刚好缓存的区间有重复的，去重
            else if(firstMap.count(i + 1))//可以接到某区间的前面
            {
                firstMap[i] = firstMap[i + 1];
                backMap[firstMap[i + 1]] = i;
                iMaxLength = max(iMaxLength, firstMap[i + 1] - i + 1);
                firstMap.erase(i + 1);
            }
            else if(backMap.count(i - 1))//可以接到某区间的后面
            {
                backMap[i] = backMap[i - 1];
                firstMap[backMap[i - 1]] = i;
                iMaxLength = max(iMaxLength, i - backMap[i - 1] + 1);
                backMap.erase(i - 1);
            }
            else if(!backMap.count(i) && !firstMap.count(i))//去重后，就算是在某区间中部也可以重新记录一个区间
            {
                firstMap[i] = i;
                backMap[i] = i;
                iMaxLength = max(iMaxLength, 1);
            }
        }
        return iMaxLength;
    }
};
// @lc code=end

