//This is for test example

#include<iostream>
#include<vector>
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
#include "1905.统计子岛屿.cpp"
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
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    int  arr1[] = {1000000000};
    int arr2[] = {5, 6, 7, 8};
    int arr3[] = {9, 10, 11, 12};
    vector<int>input1(begin(arr1),end(arr1));
    vector<int>input2(begin(arr2),end(arr2));
    vector<int>input3(begin(arr3),end(arr3));
    //vector<vector<int>> input4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};//54.螺旋矩阵
    //vector<vector<int>> input4 = {{1, 3}, {2, 6}, {8, 10},{15, 18}};//56.合并区间
    //vector<vector<int>> input4 = {{1, 3}, {3, 18}};//56.合并区间
    //vector<vector<int>> input4 = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};//74.搜索二维矩阵
    vector<vector<int>> input4 = {{1,0,1,0,1}, {1,1,1,1,1}, {0,0,0,0,0}, {1,1,1,1,1},{1,0,1,0,1}};//1905.统计子岛屿
    vector<vector<int>> input5 = {{0,0,0,0,0}, {1,1,1,1,1}, {0,1,0,1,0}, {0,1,0,1,0},{1,0,0,0,1}};//1905.统计子岛屿
    //vector<vector<int>> input4 = {{1}};//74.搜索二维矩阵
    vector<vector<char>> input6 = {{'1','1','1'}, {'0','1','0'}, {'1','1','1'}};//200.岛屿数量
    ListNode *headA = new ListNode(1);
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
    string strInput1 = "abcabcbb";
    string strInput2 = "24";


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
    iResult = solution->countSubIslands(input4, input5);
    cout<<iResult<<endl;
    //cout<<strResult<<endl;
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