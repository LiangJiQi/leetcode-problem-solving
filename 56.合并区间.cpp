/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 * 先排序保证有序，可只遍历一遍
 * 以一个区间为起点，遍历合并直至没有交界的下一区间，从新开始遍历合并，直至末尾
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool Comp(const vector<int> & a, const vector<int> & b)
    {
        return (a[0] < b[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>resultVec;
        sort(intervals.begin(), intervals.end(), Comp);//先排序，保证有序可直接遍历一次
        for(int i = 0; i < intervals.size(); )
        {
            //检查边界重合
            int iMin = intervals[i][0];
            int iMax = intervals[i][1];
            int j = i + 1;
            for(; j < intervals.size(); j++)
            {
                if((iMax >= intervals[j][0] && iMin <= intervals[j][1]))//如果边界有重合
                {
                    iMin = min(iMin, intervals[j][0]);//合并下边界
                    iMax = max(iMax, intervals[j][1]);//合并上边界
                }
                else break;
            }
            resultVec.emplace_back(vector({iMin, iMax}));//插入合并后区间
            i = j;//移动到未合并的下标处
        }
        return resultVec;
    }
};
// @lc code=end

