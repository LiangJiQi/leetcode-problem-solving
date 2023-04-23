/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <list>
#include <unordered_map>
using namespace std;
// @lc code=start
class LRUCache {
public:
    int iCapacity;//缓存上限
    list<pair<int, int>> LRUList;//pair<key,value>
    unordered_map<int, list<pair<int, int>>::iterator>LRUMap;//map<key, list 的迭代器>

    LRUCache(int capacity) {
        iCapacity = capacity;//初始化
    }
    
    int get(int key) {
        if(LRUMap.count(key))//get命中时拿到队列头部
        {
            int value = LRUMap[key]->second;
            LRUList.push_front(make_pair(key, value));
            LRUList.erase(LRUMap[key]);
            LRUMap[key] = LRUList.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(LRUMap.count(key))//put命中时更新值，且拿到队列头部
        {
            LRUMap[key]->second = value;
            get(key);
        }
        else //未命中时插入
        {
            LRUList.push_front(make_pair(key, value));
            LRUMap[key] = LRUList.begin();
            if(LRUMap.size() > iCapacity)//插入后校验上限，超过则pop
            {
                auto backEme = LRUList.back();
                LRUMap.erase(backEme.first);
                LRUList.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

