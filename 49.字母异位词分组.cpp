/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> resultVec;//乱序答案
        unordered_map<string, int> strCount;//map<key: 字符串中字符数量组成的字符串, value: 在答案中的下标位置>
        for(auto str : strs)
        {
            //计数法统计
            string charCount(26, 0);//统计里面字母的数量，将数量组成一个字符串，下标是字母，下标所在位置的数字就是数量
            for(auto c : str)
            {
                charCount[c - 'a']++;//统计加一
            }

            //排序法统计
            // string strCopy(str);
            // sort(strCopy.begin(), strCopy.end());
            // string charCount = strCopy;

            if(strCount.count(charCount))resultVec[strCount[charCount]].push_back(str);//如果在答案中已经有存过下标了
            else 
            {
                resultVec.emplace_back();//没有就先构造一个
                strCount[charCount] = resultVec.size() - 1;//记录下标
                resultVec[resultVec.size() - 1].push_back(str);//存
            }
        }
        return resultVec;
    }
};
// @lc code=end

