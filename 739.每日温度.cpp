/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 * 维护一个单调栈，遍历i时每次入栈前从栈头开始比较，如果遍历到的i数比栈内更大则出栈且记为i-index后出现更高气温
 */
#include <vector>
#include <list>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        list<pair<int, int>> downList;//单调栈，头小尾大
        vector<int>resultVec(temperatures.size(), 0);//结果答案
        for(int i = 0; i < temperatures.size(); i++)
        {
            for(auto iter =  downList.begin(); iter != downList.end(); )//遍历栈内数
            {
                if(iter->first < temperatures[i])//出现更高温
                {
                    resultVec[iter->second] = i - iter->second;//记为i - index
                    iter = downList.erase(iter);//出栈
                }
                else break;//因为是单调的所以直接结束检查
            }
            downList.emplace_front(temperatures[i], i);//入栈
        }
        return resultVec;
    }
};
// @lc code=end

