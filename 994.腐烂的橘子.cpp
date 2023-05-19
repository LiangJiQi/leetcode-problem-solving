/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */
#include <vector>
#include <set>
#include <functional>
using namespace std;
// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        set<pair<int, int>> SourceSet;//广度优先队列
        function<void(vector<vector<int>>&, int, int)> Dfs;//腐烂且将周围入列
        Dfs = [&](vector<vector<int>>& gridSet, int i, int j){
            if(gridSet[i][j] == 0)return;
            if(gridSet[i][j] == 1)gridSet[i][j] = 2;
            SourceSet.erase(make_pair(i, j));//出列
            if(j + 1 < gridSet[i].size() && gridSet[i][j + 1] == 1)SourceSet.insert(make_pair(i, j + 1));
            if(i + 1 < gridSet.size() && gridSet[i + 1][j] == 1)SourceSet.insert(make_pair(i + 1, j));
            if(j - 1 >= 0 && gridSet[i][j - 1] == 1)SourceSet.insert(make_pair(i, j - 1));
            if(i - 1 >= 0 && gridSet[i - 1][j] == 1)SourceSet.insert(make_pair(i - 1, j));
        };
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 2)SourceSet.insert(make_pair(i, j));//找所有的起源点
            }
        }
        int iReuslt = SourceSet.empty() ? 0 : -1;//检查有没有起源点
        while (!SourceSet.empty())//直到广度优先队列为空
        {
            vector<pair<int, int>>SourceVec(SourceSet.begin(), SourceSet.end());//复制一份拿来遍历
            for(const auto & p : SourceVec)Dfs(grid, p.first, p.second);//遍历复制的每个点
            iReuslt++;//深度++
        }
        

        for(const auto & n : grid)
        {
            for(const auto & m : n)
            {
                if(m == 1)return -1;//如果还有剩余没有腐烂
            }
        }
        return iReuslt;
    }
};
// @lc code=end

