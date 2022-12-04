/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string strResult = "";
        int iSize1 = num1.size() - 1;
        int iSize2 = num2.size() - 1;
        int iUpAdd = 0;//进位数，满十时向前进位的数

        //遍历用'0'来取每一个数的真实值
        while (iSize1 >= 0 || iSize2 >= 0)
        {
            if(iSize1 >= 0 && iSize2 >= 0)
            {
                strResult = (char)('0' + (num1[iSize1] + num2[iSize2] - 2 * '0' + iUpAdd) % 10) + strResult;
                iUpAdd = (num1[iSize1] + num2[iSize2] - 2 * '0' + iUpAdd) / 10;
                iSize1--;
                iSize2--;
            }
            else if(iSize1 < 0 && iSize2 >= 0)
            {
                strResult = (char)('0' + (num2[iSize2] - '0' + iUpAdd) % 10) + strResult;
                iUpAdd = (num2[iSize2] - '0' + iUpAdd) / 10;
                iSize2--;
            }
            else if(iSize2 < 0 && iSize1 >= 0)
            {
                strResult = (char)('0' + (num1[iSize1] - '0' + iUpAdd) % 10) + strResult;
                iUpAdd = (num1[iSize1] - '0' + iUpAdd) / 10;
                iSize1--;
            }
            else
            {
                break;
            }
        }
        if(iUpAdd != 0)
        {
            strResult = (char)('0' + iUpAdd) + strResult;
        }
        return strResult;
    }
};
// @lc code=end

