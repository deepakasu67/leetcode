#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        bool increasing = true;
        int i = 1;
        for(i = 1; i < arr.size();i++)
        {
            if (arr[i] == arr[i - 1])
                return false;
            if (arr[i] < arr[i - 1])
                break;
        }
        if (i == arr.size() || i == 1)
            return false;
        for(;i < arr.size();i++)
        {
            if (arr[i] == arr[i - 1])
                return false;
            if (arr[i] > arr[i - 1])
                return false;
        }
        return true;
    }
};

//int main(void)
//{
//    vector<int> arr = {5,4,3,2,1};
//    Solution obj;
//    cout<<obj.validMountainArray(arr);
//}