/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 * 把二维当成一维数组，然后用二分法查找
 */
#include <vector>
#include <math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int iVerSize = matrix.size();
        int iHorSize = iVerSize ? matrix[0].size() : 0;
        pair<int, int> head = make_pair(0, 0);
        pair<int, int> end = make_pair(iVerSize - 1, iHorSize - 1);
        pair<int, int> mid = make_pair((head.first + end.first) / 2, (head.second + end.second) / 2);

        while(true)
        {
            int iHead = head.first * iHorSize + head.second;
            int iEnd = end.first * iHorSize + end.second;
            if(iEnd < iHead)break;
            int iMid = (iHead + iEnd) / 2;
            mid = make_pair(iMid / iHorSize, iMid % iHorSize);
            if(matrix[mid.first][mid.second] == target)
            {
                return true;
            }
            else if(matrix[mid.first][mid.second] < target)
            {
                if(mid.second + 1 >= iHorSize)head = make_pair(mid.first + 1, 0);
                else head = make_pair(mid.first, mid.second + 1);
            }
            else
            {
                if(mid.second - 1 < 0)end = make_pair(mid.first - 1, iHorSize - 1);
                else end = make_pair(mid.first, mid.second - 1);
            }
        }

        return false;
    }

    /*
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int iMid = 0;//中间节点
        int iMin = 0;//头节点
        int m = matrix.size();
        int n = matrix[0].size();
        int iMax = m * n - 1;//尾节点
        //二分查找
        while(iMin <= iMax)
        {
            iMid = (iMax + iMin) / 2;
            if(matrix[iMid / n][iMid % n] > target)
            {
                iMax = iMid-1;
            }
            else if(matrix[iMid / n][iMid % n] < target)
            {
                iMin = iMid + 1;
            }
            else
            {
                return true;
            }

        }
        return false;
    }
    */
};
// @lc code=end

