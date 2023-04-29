/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 * 双指针法，头尾开始，每次选小的值向中间移动，因为缩小横坐标距离后不会有更大的值出现
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int iMaxArea = 0;
        for(int i = 0, j = height.size() - 1; i < j; )
        {
            iMaxArea = max(iMaxArea, (j - i) * min(height[i], height[j]));
            if(height[i] > height[j])j--;
            else i++;
        }
        return iMaxArea;
    }
};
// @lc code=end

