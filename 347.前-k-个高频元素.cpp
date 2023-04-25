/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int, int>countMap;//map<key: nums, value: count>
        // vector<pair<int, int>> maxCountVec;//map数据的拷贝
        // for(int n : nums)
        // {
        //     if(countMap.count(n))
        //     {
        //         auto oldCount = find(maxCountVec.begin(), maxCountVec.end(), make_pair(n, countMap[n]));
        //         oldCount->second = ++countMap[n];
        //     }
        //     else maxCountVec.push_back(make_pair(n, ++countMap[n]));
        // }
        // sort(maxCountVec.begin(), maxCountVec.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        //     return a.second > b.second;
        // });
        // vector<int> resultVec;
        // for(auto c : maxCountVec)
        // {
        //     resultVec.push_back(c.first);
        //     if(resultVec.size() == k)break;
        // }
        // return resultVec;

        
    }
};
// @lc code=end

