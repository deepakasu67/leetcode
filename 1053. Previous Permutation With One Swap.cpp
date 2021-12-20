#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int i= 0;
        //find the first peak from the right which would be culprit
        for(i = arr.size() - 2; i >= 0; )
        {
            if(arr[i] <= arr[i+1])
            {
                i--;
            }
            else
            {
                break;
            }
        }
        if (i < 0)
            return arr;
        int j = 0;
        int secondIdx = i + 1;
        for( j= i + 1; j < arr.size(); j++)
        {
            if(arr[i] > arr[j] && arr[j] > arr[secondIdx] )
            {
                secondIdx = j;
            }
        }
        swap(arr[i], arr[secondIdx]);
        return arr;
    }
};

//int main(void)
//{
//    vector<int> nums = { 3,1,1,3 };
//    Solution obj;
//    obj.prevPermOpt1(nums);
//}