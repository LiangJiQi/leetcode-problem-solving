//This is for test example

#include<iostream>
#include<vector>
#include<string.h>
//#include "1.两数之和.cpp"
//#include "26.删除有序数组中的重复项.cpp"
//#include "69.x-的平方根.cpp"
//#include "70.爬楼梯.cpp"
//#include "121.买卖股票的最佳时机.cpp"
//#include "141.环形链表.cpp"
//#include "160.相交链表.cpp"
//#include "206.反转链表.cpp"
//#include "283.移动零.cpp"
//#include "415.字符串相加.cpp"
//#include "746.使用最小花费爬楼梯.cpp"
//#include "1984.学生分数的最小差值.cpp"
//#include "3.无重复字符的最长子串.cpp"
//#include "15.三数之和.cpp"
//#include "33.搜索旋转排序数组.cpp"
//#include "46.全排列.cpp"
//#include "213.打家劫舍-ii.cpp"
//#include "54.螺旋矩阵.cpp"
//#include "56.合并区间.cpp"
//#include "74.搜索二维矩阵.cpp"
//#include "200.岛屿数量.cpp"
//#include "236.二叉树的最近公共祖先.cpp"
//#include "347.前-k-个高频元素.cpp"
//#include "875.爱吃香蕉的珂珂.cpp"
//#include "1905.统计子岛屿.cpp"
//#include "23.合并-k-个升序链表.cpp"
//#include "25.k-个一组翻转链表.cpp"
//#include "49.字母异位词分组.cpp"
//#include "128.最长连续序列.cpp"
//#include "42.接雨水.cpp"
//#include "438.找到字符串中所有字母异位词.cpp"
//#include "239.滑动窗口最大值.cpp"
//#include "76.最小覆盖子串.cpp"
//#include "189.轮转数组.cpp"
//#include "41.缺失的第一个正数.cpp"
//#include "240.搜索二维矩阵-ii.cpp"
//#include "94.二叉树的中序遍历.cpp"
//#include "101.对称二叉树.cpp"
//#include "98.验证二叉搜索树.cpp"
//#include "199.二叉树的右视图.cpp"
//#include "114.二叉树展开为链表.cpp"
//#include "105.从前序与中序遍历序列构造二叉树.cpp"
//#include "437.路径总和-iii.cpp"
//#include "994.腐烂的橘子.cpp"
#include "207.课程表.cpp"
#include "208.实现-trie-前缀树.cpp"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };


int main()
{
    //int arr1[] = {2,7,11,15};//1.两数之和
    //int arr1[] = {1,1,2};//26.删除有序数组中的重复项
    //int arr1[] = {7,1,5,3,6,4};//121.买卖股票的最佳时机
    //int arr1[] = {4,1,8,4,5};//160.相交链表
    //int arr2[] = {5,6,1,8,4,5};//160.相交链表
    //int arr1[] = {1,2,3,4,5};//206.反转链表
    //int arr1[] = {0,1,0,3,12};//283.移动零
    //int arr1[] = {1,100,1,1,1,100,1,1,100,1};//746.使用最小花费爬楼梯
    //int arr1[] = {9,4,1,7};//1984.学生分数的最小差值
    //int arr1[] = {-1,0,1,2,-1,-4,-2,-3,3,0,4};//15.三数之和
    //int arr1[] = {3,5,1};//{4,5,6,7,8,1,2,3};//33.搜索旋转排序数组
    //int arr1[] = {1,2,3};//46.全排列
    //int arr1[] = {2,3,2};//213.打家劫舍-ii
    //int arr1[] = {1, 2, 3, 4};//54.螺旋矩阵
    //int arr1[] = {1, 2, 3, 4};//56.合并区间
    //int arr1[] = {1, 1, 1, 2, 2, 3};//374.前-k-个高频元素
    //int arr1[] = {3, 6, 7, 11};//857.爱吃香蕉的珂珂
    //int arr1[] = {1000000000};//875.爱吃香蕉的珂珂
    //int arr1[] = {1,2,3,4,5};//25.k-个一组翻转链表
    //int arr1[] = {-6,8,-5,7,-9,-1,-7,-6,-9,-7,5,7,-1,-8,-8,-2,0};//128.最长连续序列
    //int arr1[] = {0,1,0,2,1,0,1,3,2,1,2,1};//42.接雨水
    //int arr1[] = {1000,999,998,997,996,995,994,993,992,991,990,989,988,987,986,985,984,983,982,981,980,979,978,977,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966};
    //int arr1[] = {-7,-8,7,5,7,1,6,0};//
    //int arr1[] = {1, 2};//189.轮转数组
    //int arr1[] = {1};//41.缺失的第一个正数
    int arr1[] = {3,9,20,15,7};//105.从前序与中序遍历序列构造二叉树
    int arr2[] = {9,3,15,20,7};//105.从前序与中序遍历序列构造二叉树
    int arr3[] = {9, 10, 11, 12};
    vector<int>input1(begin(arr1),end(arr1));
    vector<int>input2(begin(arr2),end(arr2));
    vector<int>input3(begin(arr3),end(arr3));
    //vector<vector<int>> input4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};//54.螺旋矩阵
    //vector<vector<int>> input4 = {{1, 3}, {2, 6}, {8, 10},{15, 18}};//56.合并区间
    //vector<vector<int>> input4 = {{1, 3}, {3, 18}};//56.合并区间
    //vector<vector<int>> input4 = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};//74.搜索二维矩阵
    //vector<vector<int>> input4 = {{1,0,1,0,1}, {1,1,1,1,1}, {0,0,0,0,0}, {1,1,1,1,1},{1,0,1,0,1}};//1905.统计子岛屿
    //vector<vector<int>> input5 = {{0,0,0,0,0}, {1,1,1,1,1}, {0,1,0,1,0}, {0,1,0,1,0},{1,0,0,0,1}};//1905.统计子岛屿
    //vector<vector<int>> input4 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};//240.搜索二维矩阵-ii
    //vector<vector<int>> input4 = {{2,2},{1,1},{0,0},{2,0}};//994.腐烂的橘子
    vector<vector<int>> input4 = {{1, 0}, {0, 1}};//207.课程表
    vector<vector<char>> input6 = {{'1','1','1'}, {'0','1','0'}, {'1','1','1'}};//200.岛屿数量
    vector<string> input7 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    ListNode *headA = new ListNode(input1[0]);
    ListNode *headB = new ListNode(5);
    ListNode *p = headA;
    ListNode *q = headB;
    for(int iCount = 1; iCount < input1.size();iCount++)
    {
        p->next = new ListNode(input1[iCount]);
        p = p->next;
        p->next = nullptr;
    }

    //236.二叉树的最近公共祖先
    // TreeNode *p1 = new TreeNode(3);
    // TreeNode *p2 = new TreeNode(5);
    // TreeNode *p3 = new TreeNode(1);
    // p1->left = p2;
    // p1->right = p3;
    //94.二叉树的中序遍历
    // TreeNode *p1 = new TreeNode(1);
    // TreeNode *p2 = new TreeNode(2);
    // TreeNode *p3 = new TreeNode(3);
    // p1->right = p2;
    // p2->left = p3;
    //101.对称二叉树
    // TreeNode *p1 = new TreeNode(1);
    // TreeNode *p2 = new TreeNode(2);
    // TreeNode *p3 = new TreeNode(2);
    // TreeNode *p4 = new TreeNode(3);
    // TreeNode *p5 = new TreeNode(3);
    // p1->right = p2;
    // p1->left = p3;
    // p2->right = p4;
    // p3->left = p5;
    //98.验证二叉搜索树
    // TreeNode *p1 = new TreeNode(5);
    // TreeNode *p2 = new TreeNode(1);
    // TreeNode *p3 = new TreeNode(4);
    // TreeNode *p4 = new TreeNode(3);
    // TreeNode *p5 = new TreeNode(6);
    // p1->right = p3;
    // p1->left = p2;
    // p3->right = p5;
    // p3->left = p4;
    //437.路径总和-iii.cpp
    // TreeNode *p1 = new TreeNode(10);
    // TreeNode *p2 = new TreeNode(5);
    // TreeNode *p3 = new TreeNode(-3);
    // TreeNode *p4 = new TreeNode(3);
    // TreeNode *p5 = new TreeNode(2);
    // TreeNode *p6 = new TreeNode(11);
    // TreeNode *p7 = new TreeNode(3);
    // TreeNode *p8 = new TreeNode(-2);
    // TreeNode *p9 = new TreeNode(1);
    // p1->right = p3;
    // p1->left = p2;
    // p2->left = p4;
    // p2->right = p5;
    // p4->left = p7;
    // p4->right = p8;
    // p5->right = p9;
    // p3->right = p6;

    //160.相交链表
    // p->next = new ListNode(input1[1]);
    // p->next->next = nullptr;
    // p = p->next;
    // for(int i = 1; i < input2.size();i++)
    // {
    //     q->next = new ListNode(input2[i]);
    //     if(i > 2)
    //     {
    //         p->next = q->next;
    //         p = p->next;
    //         p->next = nullptr;
    //     }
    //     q = q->next;
    //     q->next = nullptr;
    // }
    //string strInput1 = "154";//415.字符串相加
    // string strInput1 = "cbaebabacd";//438.找到字符串中所有字母异位词
    // string strInput2 = "abc";//438.找到字符串中所有字母异位词
    // string strInput1 = "ADOBECODEBANC";//76.最小覆盖子串
    // string strInput2 = "ABC";//76.最小覆盖子串
    string strInput1 = "acbbaca";//76.最小覆盖子串
    string strInput2 = "aba";//76.最小覆盖子串


    cout<<"begin test!\n"<<endl;
    //Solution* solution = new Solution();
    Solution* solution = nullptr;
    vector<int> resultVec(1);
    vector<vector<int>> resultVec2;
    int iResult = 0;
    bool bResult = false;
    ListNode *pResult = nullptr;
    //TreeNode *pResultRoot = nullptr;
    string strResult = "";
    //result = solution->twoSum(input1, input2[0]);//1.两数之和
    //iResult = solution->removeDuplicates(input1);//26.删除有序数组中的重复项
    //iResult = solution->mySqrt(17);//69.x-的平方根
    //iResult = solution->climbStairs(44);//70.爬楼梯
    //iResult = solution->maxProfit(input1);//121.买卖股票的最佳时机
    //bResult = solution->hasCycle(headA);//141.环形链表
    //pResult = solution->getIntersectionNode(headA, headB);//160.相交链表
    //pResult = solution->reverseList(headA);//206.反转链表
    //solution->moveZeroes(input1);//283.移动零
    //strResult = solution->addStrings(strInput1, strInput2);//415.字符串相加
    //iResult = solution->minCostClimbingStairs(input1);//746.使用最小花费爬楼梯
    //iResult = solution->minimumDifference(input1, 2);//1984.学生分数的最小差值
    //iResult = solution->lengthOfLongestSubstring(strInput1);
    //resultVec2 = solution->threeSum(input1);//15.三数之和
    //iResult = solution->search(input1,3);//33.搜索旋转排序数组
    //iResult = solution->rob(input1);//213.打家劫舍-ii
    //resultVec = solution->spiralOrder(input4);//54.螺旋矩阵
    //resultVec2 = solution->merge(input4);//56.合并区间
    //bResult = solution->searchMatrix(input4, 13);//74.搜索二维矩阵
    //iResult = solution->numIslands(input5);//200.岛屿数量
    //pResultRoot = solution->lowestCommonAncestor(p1, p2, p3);//236.二叉树的最近公共祖先
    //resultVec = solution->topKFrequent(input1, 2);//374.前-k-个高频元素
    //iResult = solution->minEatingSpeed(input1, 2);//875.爱吃香蕉的珂珂
    //iResult = solution->countSubIslands(input4, input5);//1905.统计子岛屿
    //pResult = solution->reverseKGroup(headA, 2);//k-个一组翻转链表
    //solution->groupAnagrams(input7);//49.字母异位词分组
    //iResult = solution->longestConsecutive(input1);//128.最长连续序列
    //iResult = solution->trap(input1);//42.接雨水
    //resultVec = solution->findAnagrams(strInput1, strInput2);//438.找到字符串中所有字母异位词
    //resultVec = solution->maxSlidingWindow(input1, 4);//239.滑动窗口最大值
    //strResult = solution->minWindow(strInput1, strInput2);//76.最小覆盖子串
    //solution->rotate(input1, 3);//189.轮转数组
    //iResult = solution->firstMissingPositive(input1);//41.缺失的第一个正数
    //bResult = solution->searchMatrix(input4, -2);//240.搜索二维矩阵-ii
    //resultVec = solution->inorderTraversal(p1);//94.二叉树的中序遍历
    //bResult = solution->isSymmetric(p1);//101.对称二叉树
    //bResult = solution->isValidBST(p1);//98.验证二叉搜索树
    //resultVec = solution->rightSideView(p1);//199.二叉树的右视图
    //solution->flatten(p1);//114.二叉树展开为链表
    //pResultRoot = solution->buildTree(input1, input2);//105.从前序与中序遍历序列构造二叉树
    //iResult = solution->pathSum(p1 , -1);//437.路径总和-iii
    //iResult = solution->orangesRotting(input4);//994.腐烂的橘子
    //bResult = solution->canFinish(2, input4);//207.课程表
    Trie* trie = new Trie();
    trie->insert("apple");
    trie->search("apple");   // 返回 True
    trie->search("app");     // 返回 False
    trie->startsWith("app"); // 返回 True
    trie->insert("app");
    trie->search("app");     // 返回 True
    //cout<<iResult<<endl;
    //cout<<strResult<<endl;
    cout<<(bResult ? "true" : "false")<<endl;
    while (pResult != nullptr)
    {
        cout<<pResult->val<<" ";
        pResult = pResult->next;
    }
    
    for(auto r : resultVec)
    {
        cout<<r<<" ";
    }
    cout<<endl;
    for(auto v : resultVec2)
    {
        for(auto i : v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    for(auto i : input1)
    {
        //cout<<i<<" ";
    }
    cout<<endl<<endl<<"end test!\n"<<endl<<endl;
    return 0;
}