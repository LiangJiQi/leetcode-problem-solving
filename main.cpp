//This is for test example

#include<iostream>
#include<vector>
//#include "1.两数之和.cpp"
//#include "26.删除有序数组中的重复项.cpp"
//#include "69.x-的平方根.cpp"
//#include "70.爬楼梯.cpp"
//#include "121.买卖股票的最佳时机.cpp"
#include "141.环形链表.cpp"
using namespace std;

int main()
{
    //int arr1[] = {2,7,11,15};//1.两数之和
    //int arr1[] = {1,1,2};//26.删除有序数组中的重复项
    int arr1[] = {7,1,5,3,6,4};//121.买卖股票的最佳时机
    int arr2[] = {9};
    vector<int>input1(begin(arr1),end(arr1));
    vector<int>input2(begin(arr2),end(arr2));
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for(int iCount = 0; iCount < 4;iCount++)
    {
        p->next = new ListNode(1);
        p = p->next;
    }

    cout<<"begin test!\n"<<endl;
    Solution* solution = new Solution();
    vector<int> result(1);
    int iResult = 0;
    bool bResult = false;
    //result = solution->twoSum(input1, input2[0]);//1.两数之和
    //iResult = solution->removeDuplicates(input1);//26.删除有序数组中的重复项
    //iResult = solution->mySqrt(17);//69.x-的平方根
    //iResult = solution->climbStairs(44);//70.爬楼梯
    //iResult = solution->maxProfit(input1);//121.买卖股票的最佳时机
    bResult = solution->hasCycle(head);//141.环形链表
    cout<<iResult<<endl;
    for(auto r : result)
    {
        //cout<<r<<" ";
    }
    for(auto i : input1)
    {
        //cout<<i<<" ";
    }
    cout<<endl<<endl<<"end test!\n"<<endl<<endl;
    return 0;
}