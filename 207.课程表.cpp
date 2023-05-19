/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, unordered_set<int>> requiresMap;
        for(const auto & r : prerequisites) requiresMap[r[0]].insert(r[1]);

        function<bool(vector<int>)> CheckFunc;
        CheckFunc = [&](vector<int> checkQueue)->bool{
            bool bCheck = false;
            if(!requiresMap.count(checkQueue.back())) return bCheck;
            unordered_set<int>QueueCopy(checkQueue.begin(), checkQueue.end());
            for(const auto & s : requiresMap[checkQueue.back()])
            {
                if(QueueCopy.count(s))
                {
                    for(const int & i : QueueCopy)
                    {
                        requiresMap.erase(i);
                    }
                    return true;
                }
                QueueCopy.insert(s);
                checkQueue.push_back(s);
                bCheck = bCheck || CheckFunc(checkQueue);
                if(bCheck)return bCheck;
            }
            return bCheck;
        };

        for(auto s = requiresMap.begin(); s != requiresMap.end(); s++)
        {
            bool bCheck = false;
            vector<int>checkQueue;
            checkQueue.emplace_back(s->first);
            if(CheckFunc(checkQueue))s = requiresMap.begin();
        }
        int iCount = 0;
        unordered_set<int> Courses;
        for(auto s : requiresMap)
        {
            if(!Courses.count(s.first))
            {
                iCount++;
                Courses.insert(s.first);
            }
            for(auto i : s.second)
            {
                if(!Courses.count(i))
                {
                    Courses.insert(i);
                    iCount++;
                }
            }
        }

        return (iCount >= numCourses);
    }
};
// @lc code=end

