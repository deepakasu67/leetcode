//
// Created by Deepak Sahu on 1/2/22.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace  std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        unordered_set<int> num(arr.begin(), arr.end());

        int maxi = 0;
        for(int i = 0 ;i <arr.size(); i++)
        {
            for(int j = i + 1; j < arr.size(); j++)
            {
                int a = arr[i];
                int b = arr[j];
                int cnt = 2;
                while(num.count(a+b))
                {
                    cnt++;
                    b = a+ b;
                    a = b -a ;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi > 2 ? maxi : 0;
    }
};

//int main(void)
//{
//    //vector<int> nums = {1,3,7,11,12,14,18};
//    vector<int> nums = {1,2,3,4,5,6,7,8};
//    cout<<Solution().lenLongestFibSubseq(nums);
//}
