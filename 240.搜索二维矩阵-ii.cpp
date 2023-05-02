/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //暴力解
        // for(const auto & m : matrix)
        // {
        //     for(const int & n : m)
        //     {
        //         if(n == target)return true;
        //     }
        // }
        
        //二分查找
        int iSizeN = matrix.size();
        int iSizeM = matrix.empty() ? 0 : matrix[0].size();
        // for(int i = 0; i < iSizeN; i++)
        // {
        //     if(matrix[i][0] > target)break;
        //     int iHead = 0, iBack = iSizeM - 1;
        //     while(iHead <= iBack)
        //     {
        //         int iMid = (iHead + iBack) / 2;
        //         int iNum = matrix[i][iMid];
        //         if(iNum == target)return true;
        //         else if(iNum < target)iHead =  iMid + 1;
        //         else iBack = iMid - 1;
        //     }
        // }

        //对于坐标[x][y]处的数值来讲，0到y、[x][y]、x到n是严格递增的，利用这个性质不断比较[x][y]
        //大于则舍弃x行，小于则舍弃y列，可以不断的逼近直至越界
        pair<int, int> startIndex(0, iSizeM - 1);
        while(startIndex.first < iSizeN && startIndex.second >= 0)
        {
            if(matrix[startIndex.first][startIndex.second] == target) return true;
            else if(matrix[startIndex.first][startIndex.second] < target) startIndex.first++;
            else startIndex.second--;
        }

        return false;
    }
};
// @lc code=end

