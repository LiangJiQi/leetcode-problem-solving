/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Trie {
public:
    Trie() {
        root = nullptr;
    }
    //对于插入
    void insert(string word) {
        TreeNode * p = root;
        for(const char & c : word)
        {
            if(!p)//如果还没建立
            {
                root = new TreeNode(c);
                root->nextMap[c] = new TreeNode(c);//新建一个树的根
                p = root->nextMap[c];
            }
            else//如果已经建立了
            {
                if(!p->nextMap.count(c))//查找树的路径
                {
                    p->nextMap[c] = new TreeNode(c);//没有就插入新节点
                }
                p = p->nextMap[c];//遍历新节点
            }
        }
        p->strWord = word;//叶子节点保存插入值
    }
    //对于搜索
    bool search(string word) {
        if(!root)return false;//保平安
        TreeNode * p = root;//遍历节点
        for(const char & c : word)
        {
            if(!p->nextMap.count(c))return false;//如果没有通路则失败
            p = p->nextMap[c];
        }
        if(word != p->strWord)return false;//有通路，但不是叶子节点，只是一个前缀也失败
        return true;
    }
    //对于搜索前缀
    bool startsWith(string prefix) {
        if(!root)return false;//保平安
        TreeNode * p = root;//遍历节点
        for(const char & c : prefix)
        {
            if(!p->nextMap.count(c))return false;//没有通路失败
            p = p->nextMap[c];
        }
        return true;
    }

private:
    struct TreeNode //每个节点
    {
        char cValue;//每个节点的值
        string strWord;//如果是叶子节点，则值存在，为插入的值
        unordered_map<char, TreeNode*> nextMap;//每个节点的下一孩子
        TreeNode(const char & c): cValue(c), strWord("") {};
    };
    TreeNode *root;//根，根的下一节点才是真正前缀树的根节点
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

