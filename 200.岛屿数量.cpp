/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 * 深度优先递归算法，将遍历到的数字改变，以防下次重复遍历，改变后向各个方向继续遍历，每一次深度优先递归结束后都记一个岛屿。
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:

    void dfs(vector<vector<char>> & grid, int i, int j)
    {
        if(grid[i][j] != '1')return;//如果遍历过或者是水则跳过
        grid[i][j] = '2';//改变为不使用的数字
        //如果没有超过边界就继续递归
        if(j + 1 < grid[i].size())dfs(grid, i, j + 1);
        if(j - 1 >= 0)dfs(grid, i, j - 1);
        if(i + 1 < grid.size())dfs(grid, i + 1, j);
        if(i - 1 >= 0)dfs(grid, i - 1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int iCount = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);//深度优先递归
                    iCount++;//记一个岛屿数量
                }
            }
        }
        return iCount;
    }
};
// @lc code=end

