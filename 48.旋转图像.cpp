/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int iSize = matrix.size();
        //遍历全部，每次只设置一次
        // vector<vector<int>>matrixCopy(matrix);
        // for(int i = 0; i < iSize; i++)
        // {
        //     for(int j = 0; j < iSize; j++)
        //     {
        //         matrix[j][iSize - i -1] = matrixCopy[i][j];
        //     }
        // }

        //遍历四分之一部分，每次旋转四次一圈
        // for(int i = 0; i < iSize / 2; i++)
        // {
        //     for(int j = 0; j < (iSize + 1) / 2; j++)
        //     {
        //         int iTemp = matrix[i][j];
        //         matrix[i][j] = matrix[iSize - j - 1][i];
        //         matrix[iSize - j - 1][i] = matrix[iSize - i - 1][iSize - j - 1];
        //         matrix[iSize - i - 1][iSize - j - 1] = matrix[j][iSize - i - 1];
        //         matrix[j][iSize - i - 1] = iTemp;
        //     }
        // }

        //翻转法
        auto reverFunc = [iSize](vector<vector<int>> & ReverMatrix, int iIndex){
            int iStart = 0, iEnd = iSize - 1;
            while(iStart < iEnd)swap(ReverMatrix[iStart++][iIndex], ReverMatrix[iEnd--][iIndex]);
        };
        for(int i = 0; i < iSize; i++)reverFunc(matrix, i);//垂直翻转
        for(int i = 0; i < iSize; i++)//对角翻转
        {
            for(int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //n0 10 20 00     00 01 02 0n
        //n1       01     10 11 12 1n
        //n2       02     20 21 22 2n
        //nn 2n 1n 0n     n0 n1 n2 nn


    }
};
// @lc code=end

