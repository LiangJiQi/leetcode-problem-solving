/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int iResult = s.empty() ? 0 : 1;
        //普通解法
        // for(int i = 0;i < s.size();i++)
        // {
        //     for(int j = i + 1;j < s.size();j++)
        //     {
        //         bool bRepeat = false;
        //         int iRepeat = j;
        //         for(int k = j - 1; k >= i;k--)
        //         {
        //             if(s[k] == s[j])
        //             {
        //                 bRepeat = true;
        //                 iRepeat = k;
        //                 break;
        //             }
        //         }
        //         if(!bRepeat && iResult < j - i + 1)
        //         {
        //             iResult = j - i + 1;
        //         }
        //         else if(bRepeat)
        //         {
        //             i = iRepeat;
        //             break;
        //         }
        //     }
        // }

        //滑动窗口
        int iBegin = 0;
        int iMid = 0;
        for(int iEnd = 1;iEnd < s.size();iEnd++)
        {
            bool bRepeat = false;
            for(iMid = iEnd - 1;iMid >= iBegin;iMid--)
            {
                if(s[iEnd] == s[iMid])
                {
                    bRepeat = true;
                    iBegin = iMid + 1;
                    break;
                }
            }
            if(!bRepeat && iEnd - iBegin + 1 > iResult)
            {
                iResult = iEnd - iBegin + 1;
            }

        }


        return iResult;
    }
};
// @lc code=end

