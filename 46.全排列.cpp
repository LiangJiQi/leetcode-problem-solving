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
        packVec.push_back(surNum[iIndex]);
        surNum.erase(surNum.begin() + iIndex);
        if(surNum.empty())
        {
            resultVec.push_back(packVec);
            return;
        }
        for(int i = 0;i < surNum.size();i++)
        {
            vector<int> packNewVec(packVec.begin(), packVec.end());
            vector<int> surNewNum(surNum.begin(), surNum.end());
            RePack(packNewVec, surNewNum, i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        for(int i = 0;i < nums.size();i++)
        {
            vector<int> packVec;
            vector<int> surNum(nums.begin(), nums.end());
            RePack(packVec, surNum, i);
        }

        return resultVec;

    }
};
// @lc code=end

