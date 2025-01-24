/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    // 初始化数字对应的字母
    void Init(unordered_map<char, vector<char>>& numToChar)
    {
        numToChar['2'] = {'a','b','c'};
        numToChar['3'] = {'d','e','f'};
        numToChar['4'] = {'h','i','g'};
        numToChar['5'] = {'j','k','l'};
        numToChar['6'] = {'m','n','o'};
        numToChar['7'] = {'p','q','r','s'};
        numToChar['8'] = {'t','u','v'};
        numToChar['9'] = {'w','x','y','z'};
    }

    // 根据数字获取所有的对应字母
    vector<char> GetWord(char cNum, const unordered_map<char, vector<char>>& numToChar)
    {
        if (numToChar.find(cNum) != numToChar.end())
        {
            return numToChar.at(cNum);
        }
        return {};
    }

    // 递归前缀遍历所有可能
    void DeepRun(string front, string res_digits, const unordered_map<char, vector<char>>& numToChar, vector<string> & result)
    {
        // 递归结束条件，后续没有更多字符
        if (res_digits.size() <= 0)
        {
            if (front.size() > 0) // 是否有效
            {
                result.push_back(front);    
            }
            return;
        }
        // 递归继续进行
        else
        {
            // 取对应的所有字母
            vector<char> allChars = GetWord(res_digits[0], numToChar);
            if (allChars.size() > 0)
            {
                for(auto c : allChars)
                {
                    // 追加到前缀中 并递归剩余数字
                    DeepRun(front + c, res_digits.substr(1, res_digits.size() - 1), numToChar, result);
                }    
            }
            else
            {
                DeepRun(front, res_digits.substr(1, res_digits.size() - 1), numToChar, result); // 没有对应字母时也可以继续递归
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> numToChar;
        vector<string> result;
        Init(numToChar);
        DeepRun("", digits, numToChar, result);
        return result;
    }
};
// @lc code=end

