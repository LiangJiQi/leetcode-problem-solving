/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 * 1.切块复制后复制回去，2.复制全部，遍历按偏移替换，3.翻转全部一次，切成两部分分别翻转一次
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        // vector<int> head(nums.begin(), nums.begin() + nums.size() - k);//按k切分成两部分复制出来
        // vector<int> back(nums.begin() + nums.size() - k, nums.end());
        // copy(back.begin(), back.end(), nums.begin());//复制回去
        // copy(head.begin(), head.end(), nums.begin() + k);


        //额外数组
        // vector<int> copyNums(nums.begin(), nums.end());//全部复制出来
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     // if(i < k) nums[i] = copyNums[nums.size() - k + i];//按照位置偏移遍历替换（1）
        //     // else nums[i] = copyNums[i - k];

        //     //nums[(i + k) % nums.size()] = copyNums[i];//按照位置偏移遍历替换（2）
        // }

        //翻转法
        auto rever = [](vector<int> & nums, int iStart, int iEnd){//翻转数组的函数
            while(iStart < iEnd)swap(nums[iStart++], nums[iEnd--]);
        };
        rever(nums, 0, nums.size() - 1);//全部翻转一次
        rever(nums, 0, k - 1);//按k切分成两部分分别翻转一次
        rever(nums, k, nums.size() - 1);
    }
};
// @lc code=end

