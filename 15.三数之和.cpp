/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start

class Solution {


public:

    //冒泡排序
    void BubblesSort(vector<int>& nums)
    {
        for(int i = nums.size() - 1;i > 0;i--)
        {
            for(int j = 0;j < i;j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }
    //快速排序
    void QuickSort(vector<int>& nums, int iBegin, int iEnd)
    {
        if(iEnd<=iBegin)return;
        int iHead = iBegin;
        int iBack = iEnd;
        int iProvi = nums[iBegin];

        //挖坑法
        // while (iHead < iBack)
        // {
        //     while (iBack > iHead && nums[iBack] >= iProvi)
        //     {
        //         iBack--;
        //     }
        //     nums[iHead] = nums[iBack];
        //     while (iHead < iBack && nums[iHead] <= iProvi)
        //     {
        //         iHead++;
        //     }
        //     nums[iBack] = nums[iHead];
        // }
        // nums[iHead] = iProvi;

        //不挖坑，交换法
        while (iHead < iBack)
        {
            while (iHead < iBack && nums[iBack] >= iProvi)
            {
                iBack--;
            }
            while (iHead < iBack && nums[iHead] <= iProvi)
            {
                iHead++;
            }
            swap(nums[iHead],nums[iBack]);
        }
        swap(nums[iBegin], nums[iHead]);

        QuickSort(nums,iBegin,iHead-1);
        QuickSort(nums,iBack+1,iEnd);
        return;
    }

    //堆排序
    void BulidHeap(vector<int>& nums, int iBegin, int iEnd)
    {

        while(iBegin < iEnd)
        {
            int iLeftChildIndex = iBegin * 2 + 1;
            int iRightChildIndex = iLeftChildIndex + 1;
            int iMaxChildIndex = iLeftChildIndex;
            if(iBegin > iEnd || iLeftChildIndex > iEnd)break;
            if(iRightChildIndex <= iEnd)
            {
                iMaxChildIndex = nums[iLeftChildIndex] > nums[iRightChildIndex] ? iLeftChildIndex : iRightChildIndex;
            }
            if(nums[iMaxChildIndex] > nums[iBegin])
            {
                swap(nums[iMaxChildIndex], nums[iBegin]);
            }
            else
            {
                break;
            }
            iBegin = iMaxChildIndex;
        }

    }
    void HeapSort(vector<int>& nums)
    {
        int iSize = nums.size() - 1;
        for(int i = (iSize - 1) / 2;i >= 0; i--)
        {
            BulidHeap(nums, i, iSize);
        }

        while(iSize >= 0)
        {
            swap(nums[0], nums[iSize--]);
            BulidHeap(nums,0,iSize);
        }
    }

    //选择排序
    void SelectSort(vector<int>& nums)
    {
        for(int i = nums.size()-1;i >= 0;i--)
        {
            int iMaxIndex = i;
            for(int j = 0;j < i;j++)
            {
                if(nums[j] > nums[iMaxIndex])iMaxIndex = j;
            }
            swap(nums[i],nums[iMaxIndex]);
        }
    }
    //插入排序
    void InsertSort(vector<int>& nums)
    {
        for(int i = 1;i < nums.size();i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(nums[i] < nums[j])
                {
                    nums.insert(nums.begin() + j, nums[i]);
                    nums.erase(nums.begin() + i + 1);
                    break;
                }
            }
        }
    }

    //归并排序
    void MergeNums(vector<int>& nums, int iLeftBegin, int iLeftEnd, int iRightBegin, int iRightEnd)
    {


    }
    void MergeSort(vector<int>& nums)
    {
        for(int i = 1;i <= nums.size() / 2;i++)
        {
            //MergeNums(nums,);
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>reslutVec;
        //先排序

        //库函数排序
        sort(nums.begin(),nums.end());
        //冒泡排序
        //BubblesSort(nums);
        //快速排序
        //QuickSort(nums, 0, nums.size() - 1);
        //堆排序
        //HeapSort(nums);
        //选择排序
        //SelectSort(nums);
        //插入排序
        //InsertSort(nums);
        //归并排序
        //MergeSort(nums);

        //首尾收缩遍历查找
        int iBegin = 0;
        int iEnd = nums.size() - 1;
        int iMid = iBegin + 1;
        while (iBegin < nums.size())
        {
            iMid = iBegin + 1;
            iEnd = nums.size() - 1;
            while (iMid < iEnd)
            {
                int iAdd = nums[iBegin] + nums[iEnd] + nums[iMid];
                if(iAdd == 0)
                {
                    reslutVec.push_back({nums[iBegin], nums[iEnd], nums[iMid]});
                    do
                    {
                        iEnd--;
                    } while (iEnd > iMid && iEnd+1 < nums.size() && (nums[iEnd] == nums[iEnd+1]));
                    
                    do
                    {
                        iMid++;
                    } while (iEnd > iMid && iMid-1 >= 0 && (nums[iMid] == nums[iMid-1]));
                }
                else if(iAdd > 0)
                {
                    iEnd--;
                }
                else if (iAdd < 0)
                {
                    iMid++;
                }
            }
    
            do
            {
                iBegin++;
            }while(nums.size() > iBegin && (nums[iBegin] == nums[iBegin - 1]));
            
        }

        return reslutVec;
    }
};
// @lc code=end

