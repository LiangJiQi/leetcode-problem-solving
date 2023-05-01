/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 * 同时维护一个窗口和该窗口的有序拷贝，不断的移动窗口和取最大值
 */
#include <vector>
#include <queue>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> resultVec;//答案
        queue<int> windowQueue;//窗口队列
        multiset<int> windowSet;//窗口队列的有序拷贝
        for(const int & n : nums)
        {
            if(windowQueue.size() < k)//数量不够则填充到窗口
            {
                windowQueue.push(n);
                windowSet.insert(n);
            }
            if(windowQueue.size() == k)//数量足够
            {
                resultVec.push_back(*(--windowSet.end()));//先取最大值
                windowSet.erase(windowSet.find(windowQueue.front()));//在有序拷贝中删除窗口的第一个数
                windowQueue.pop();//窗口移动
            }
        }

        return resultVec;
    }
};
// @lc code=end

