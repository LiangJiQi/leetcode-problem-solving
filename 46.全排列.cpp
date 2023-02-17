/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:

    vector<vector<int>> resultVec;
    void RePack(vector<int>& packVec, vector<int>& surNum, int iIndex)
    {
        packVec.push_back(surNum[iIndex]);//从剩余的向排好的中插入一个
        surNum.erase(surNum.begin() + iIndex);//插入后删除
        if(surNum.empty())//如果没有剩余的了
        {
            resultVec.push_back(packVec);//作为一种排序可能结果存入答案
            return;//并结束
        }
        for(int i = 0;i < surNum.size();i++)//如果还有剩余的，继续开头的插入过程
        {
            vector<int> packNewVec(packVec.begin(), packVec.end());
            vector<int> surNewNum(surNum.begin(), surNum.end());
            RePack(packNewVec, surNewNum, i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        for(int i = 0;i < nums.size();i++)
        {
            vector<int> packVec;//已经排好的数
            vector<int> surNum(nums.begin(), nums.end());//除去排好的还剩余的数
            RePack(packVec, surNum, i);
        }

        return resultVec;

    }
};
// @lc code=end

