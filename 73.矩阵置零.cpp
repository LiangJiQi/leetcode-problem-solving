/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<int>horSet;//记录需要置零的行
        set<int>verSet;//记录需要置零的列
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    horSet.insert(i);
                    verSet.insert(j);
                }
            }
        }
        for(const int & i : horSet)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                matrix[i][j] = 0;
            }
        }
        for(const int & j : verSet)
        {
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};
// @lc code=end

