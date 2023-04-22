/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> resultVec;//求解结果
        int iVerSize = matrix.size();//垂直高度
        int iHorSize = iVerSize > 0 ? matrix[0].size() : 0;//水平高度
        pair<int, int>horSize = make_pair(0, iHorSize);//水平遍历范围
        pair<int, int>verSize = make_pair(0, iVerSize);//垂直遍历范围
        int iDire = 0;//当前方向，0向右、1向下、2向左、3向上
        int m = horSize.first;//当前遍历到的节点二维下标
        int n = verSize.first;//当前遍历到的节点一维下标

        while(resultVec.size() < iVerSize * iHorSize)//全部遍历达到数量就可以结束
        {
            if(iDire == 0)//向右遍历
            {
                while (m <= horSize.second - 1)resultVec.push_back(matrix[n][m++]);
                verSize.first++;//提高垂直下限，缩小垂直范围
                iDire = 1;//改变方向向下
                m--;//更新当前遍历节点的下标
                n++;//更新当前遍历节点的下标
            }
            else if(iDire == 1)
            {
                while (n <= verSize.second - 1)resultVec.push_back(matrix[n++][m]);
                horSize.second--;//减少水平上限，缩小水平范围
                iDire = 2;
                n--;
                m--;
            }
            else if (iDire == 2)
            {
                while (m >= horSize.first)resultVec.push_back(matrix[n][m--]);
                verSize.second--;
                iDire = 3;
                m++;
                n--;
            }
            else
            {
                while (n >= verSize.first)resultVec.push_back(matrix[n--][m]);
                horSize.first++;
                iDire = 0;
                n++;
                m++;
            }
            if(horSize.first >= horSize.second && verSize.first >= verSize.second)break;//保底结束遍历
        }
        return resultVec;
    }
};
// @lc code=end

