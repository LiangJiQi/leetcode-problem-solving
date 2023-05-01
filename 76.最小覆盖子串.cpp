/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())return "";
        unordered_map<char, int> countTString;
        unordered_map<char, int> countSString;
        for(const char & c : t)countTString[c]++;
        // for(const char & c : s)
        // {
        //     if(countTString.count(c)) countSString[c]++;
        // }
        // for(auto & c : countTString)
        // {
        //     if(!countSString.count(c.first))return "";
        //     if(countSString[c.first] < c.second)return "";
        // }
        string strResult(s.size() + 1, 0);
        for(int i = 0, j = 0; i < s.size() && j < s.size(); )
        {
            while(countSString.size() < countTString.size() || (countTString.count(s[j]) && countSString[s[j]] < countTString[s[j]]))
            {
                if(countTString.count(s[j]))
                {
                    countSString[s[j]]++;
                }
                if(++j > s.size())break;
            }

            while(countSString.size() >= countTString.size())
            {
                if(countTString.count(s[i]))
                {
                    if(countSString[s[i]] < countTString[s[i]])break;
                }
                if(j - i < strResult.size())strResult = string(s.begin() + i, s.begin() + j);
                if(countTString.count(s[i]))
                {
                    if(!(--countSString[s[i]]))countSString.erase(s[i]);
                }
                if(++i >= j)break;
            }
        }
        return strResult.size() == s.size() + 1 ? "" : strResult;
    }
};
// @lc code=end

