/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */
#include<cmath>

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {

        //牛顿法逼近平方根,输入m,求m的平方根
        //其实是求一个 x 值，使其满足 x^2 = m，令 f(x) = x^2 - m ，其实就是求方程 f(x) = 0 的根。
        //直接取x = m处的点(x1,y1)作f(x)切线，其切线的零点(x2,0)的x坐标x2会比 x = m更接近f(x)的根
        //再取x = x2做f(x)的切线，如此循环迭代取值，其切线的零点(xn,0)会不断逼近f(x)的根，
        //直至满足所需要的误差时结束取值。
        //f(x) 的导函数是 f'(x) = 2 * x。f(x)的在(x1,y1)切线方程就为 y = 2*x1*(x - x1) + y1
        //其中y1=x1^2 - m,那么切线方程也为 y = 2*x1*(x - x1) + x1^2 - m,
        //而其中x2的值为切线方程y=0时，即0 = 2*x*(x - x1) + x1^2 - m时
        //求x即可得x2的值
        //0 = 2*x1*x - x1^2 - m
        //m + x1^2 = 2*x1*x
        //(m + x1^2)/(2*x1) = x
        //x = (m/x1 + x1)/2
        //即x2 = (m/x1 + x1)/2

        double fMid = (double)x;
        do
        {
            if(abs(fMid * fMid - (double)x) < 0.0000000000001f)
            {
                return (int)fMid;
            }
            else
            {
                fMid = ((double)x / fMid + fMid) / 2.0f;
            }

        } while (true);
    }
};
// @lc code=end

