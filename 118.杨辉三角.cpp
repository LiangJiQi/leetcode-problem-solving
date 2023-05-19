/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>resultVec;
        for(int i = 0; i < numRows; i++)
        {
            if(resultVec.size() < i + 1)resultVec.resize(i + 1);
            resultVec[i].resize(i + 1);
            for(int j = 0; j < i + 1; j++)
            {
                if(j == 0 || j == i)
                {
                    resultVec[i][j] = 1;
                    continue;
                }
                resultVec[i][j] = resultVec[i - 1][j] + resultVec[i - 1][j - 1];
            }
        }

        return resultVec;
    }
};
// @lc code=end

