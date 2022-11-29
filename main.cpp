//This is for test example

#include<iostream>
#include<vector>
//#include "1.两数之和.cpp"
#include "26.删除有序数组中的重复项.cpp"
using namespace std;

int main()
{
    //int arr1[] = {2,7,11,15};//1.两数之和
    int arr1[] = {1,1,2};
    int arr2[] = {9};
    vector<int>input1(begin(arr1),end(arr1));
    vector<int>input2(begin(arr2),end(arr2));

    cout<<"begin test!\n"<<endl;
    Solution* solution = new Solution();
    vector<int> result(1);
    int iResult = 0;
    //result = solution->twoSum(input1, input2[0]);//1.两数之和
    iResult = solution->removeDuplicates(input1);//删除有序数组中的重复项
    cout<<iResult<<endl;
    for(auto r : result)
    {
        cout<<r<<" ";
    }
    for(auto i : input1)
    {
        cout<<i<<" ";
    }
    cout<<endl<<endl<<"end test!\n"<<endl<<endl;
    return 0;
}