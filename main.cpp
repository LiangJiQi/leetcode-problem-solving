//This is for test example

#include<iostream>
#include<vector>
#include"1.两数之和.cpp"
using namespace std;

int main()
{
    int arr1[] = {2,7,11,15};
    int arr2[] = {9};
    vector<int>input1(begin(arr1),end(arr1));
    vector<int>input2(begin(arr2),end(arr2));

    cout<<"begin test!\n"<<endl;
    Solution* solution = new Solution();
    vector<int> result(1);
    result = solution->twoSum(input1, input2[0]);
    for(auto r : result)
    {
        cout<<r<<" ";
    }
    cout<<endl<<endl<<"end test!\n"<<endl<<endl;
    return 0;
}