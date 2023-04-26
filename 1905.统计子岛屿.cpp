/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 * 把问题简化为计算独立岛屿的数量：构造一个新的二维数组，grid1和grid2中都为1的置为2,保留grid2中的1，遍历计算新二维中为2且不与1相邻的独立岛屿数量
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:

    bool dfs(vector<vector<int>>& grid2, int i, int j)
    {
        if(grid2[i][j] == 1)return false;//与1相邻说明不是全包含
        if(grid2[i][j] == 0)return true;//临界说明可以是独立岛屿
        if(grid2[i][j] == 3)return true;//已经遍历过的岛屿
        if(grid2[i][j] == 2)grid2[i][j] = 3;//修改遍历过的标记
        bool check[4] = {true, true, true, true};//四个方向中是否没有与1相邻
        if(i + 1 < grid2.size())
        {
            check[0] = dfs(grid2, i+1, j);
        }
        if(i - 1 >= 0)
        {
            check[1] = dfs(grid2, i-1, j);
        }
        if(j + 1 < grid2[i].size())
        {
            check[2] = dfs(grid2, i, j+1);
        }
        if(j - 1 >= 0)
        {
            check[3] = dfs(grid2, i, j-1);
        }
        return check[0] && check[1] && check[2] && check[3];
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //构造新数组
        for(int i = 0; i < grid2.size(); i++)
        {
            for(int j = 0; j < grid2[i].size(); j++)
            {
                if(grid1[i][j] == 1 && grid2[i][j] == 1)
                {
                    grid2[i][j] = 2;//都为1置为2,表示包含关系
                }
                else if(grid1[i][j] == 1 && grid2[i][j] == 0)
                {
                    grid2[i][j] = 0;//仅保留grid2中的1,用来判断是否全包含
                }
            }
        }
        int iCount = 0;
        for(int i = 0; i < grid2.size(); i++)
        {
            for(int j = 0; j < grid2[i].size(); j++)
            {
                if(grid2[i][j] == 2)
                {
                    if(dfs(grid2, i, j))iCount++;//深度优先遍历，计算为2且不与1相邻的独立岛屿数量
                }
            }
        }
        return iCount;
    }
};
// @lc code=end

