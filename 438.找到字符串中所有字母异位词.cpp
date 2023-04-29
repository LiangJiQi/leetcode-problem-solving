/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 * 滑动窗口....
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> resultVec;//答案结果
        string strStack;//保存s中子串，子串长度跟p一样
        string countPString(26, 0);//p中字母数量统计
        for(const char& c : p)
        {
            countPString[c - 'a']++;
        }
        string countMap(26, 0);//子串中字母数量统计
        for(int i = 0; i < s.size(); i++)
        {
            if(strStack.size() < p.size())//长度不够就追加，同时统计字母数量
            {
                strStack.append(1, s[i]);//追加
                countMap[s[i] - 'a']++;//统计
            }
            if(strStack.size() == p.size())//长度已够时
            {
                if(!countPString.compare(countMap))resultVec.push_back(i - p.size() + 1);//如果字母数量相同说明是异位词，记录答案
                countMap[*strStack.begin() - 'a']--;//减少统计数量
                strStack.erase(strStack.begin());//将头个字母删去，保持子串连续
            }
        }

        return resultVec;
    }
};
// @lc code=end

