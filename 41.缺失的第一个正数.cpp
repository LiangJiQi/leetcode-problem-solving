/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int iMinNum = 1;
        //sort ?
        // set<int>numsCopy(nums.begin(), nums.end());//排序加去重
        // for(const int & n : numsCopy)//从正数开始，不断提高最小值与之比较
        // {
        //     if(n <= 0)continue;
        //     if(n != iMinNum)break;
        //     iMinNum++;
        // }
        
        //not sort hash map
        // iMinNum = 0;
        // unordered_map<int, int> countMap;//hash表存储记录,<key:值 ,value:计数>
        // for(const int & n : nums)
        // {
        //     if(n > 0)countMap[n]++;
        // }
        // while (true)
        // {
        //     if(!countMap.count(++iMinNum))break;//不断提高最小值，检查记录中是否有
        // }

        //not sort swap
        //把nums数组的下标和数值看作都是严格加一递增的，遍历nums时，不断置换填充0到i之间的数值并让答案随之增加
        iMinNum = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0 && nums[i] <= nums.size())//如果数值在数组大小范围内
            {
                if(nums[nums[i] - 1] != nums[i])//该数值对应的下标还不是严格值
                {
                    swap(nums[nums[i] - 1], nums[i]);//交换
                    i--;//对交换过来的数值再判断一次
                }
                while (true)
                {
                    if(nums[iMinNum - 1] == iMinNum)iMinNum++;//看一下答案能否提高
                    else break;
                }
            }
        }

        return iMinNum;

    }
};
// @lc code=end

