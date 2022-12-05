/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */
#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int iResult = __INT_MAX__;
        //常规解法，先排序，后遍历一遍取k区间首尾差值最小

        //排序
        //sort(nums.begin(),nums.end());//库函数
        //冒泡排序
        // for(int i = nums.size() - 1; i > 0 ;i--)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         if(nums[j] > nums[j + 1])
        //         {
        //             swap(nums[j], nums[j + 1]);
        //         }
        //     }
        // }
        //快速排序，快排，二分排序

        //堆排序
        
        //https://zhuanlan.zhihu.com/p/42586566
        //选择排序
        //在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
        //从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
        //重复第二步，直到所有元素均排序完毕。

        //插入排序
        //把待排序的数组分成已排序和未排序两部分，初始的时候把第一个元素认为是已排好序的。
        //从第二个元素开始，在已排好序的子数组中寻找到该元素合适的位置并插入该位置。
        //重复上述过程直到最后一个元素被插入有序子数组中。


        //取k区间首尾差值最小值
        for(int i = 0,j = k - 1;i < nums.size() && j < nums.size();i++,j++)
        {
            if(nums[j] - nums[i] < iResult)
            {
                iResult = nums[j] - nums[i];
            }
        }
        return iResult;
    }
};
// @lc code=end

