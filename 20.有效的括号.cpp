/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <stack>
#include <functional>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> ValidStack;//先进后处的栈去匹配
        auto Check = [](const char & a, const char & b){
            if(a == '(' && b == ')')return true;
            if(a == '[' && b == ']')return true;
            if(a == '{' && b == '}')return true;
            return false;
        };
        for(int i = 0; i < s.size(); i++)
        {
            if(ValidStack.empty())ValidStack.push(s[i]);
            else if(Check(ValidStack.top(), s[i]))ValidStack.pop();
            else ValidStack.push(s[i]);
        }
        return ValidStack.empty();
    }
};
// @lc code=end

