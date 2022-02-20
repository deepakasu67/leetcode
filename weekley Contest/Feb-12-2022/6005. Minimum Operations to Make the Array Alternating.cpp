//
// Created by Deepak Sahu on 2/12/22.
//
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        unordered_map<int, int> freqMapForOdd;
        unordered_map<int, int> freqMapForEven;
        int evenSize = 0;
        int oddSize = 0;
        for(int i  =0 ;i < nums.size(); i++)
        {
            if(i %2 == 1)
            {
                oddSize++;
                freqMapForOdd[nums[i]]++;
            }
            else {
                evenSize++;
                freqMapForEven[nums[i]]++;
            }
        }
        vector<pair<int,int>> oddCount(freqMapForOdd.begin(), freqMapForEven.end());
        vector<pair<int,int>> evenCount(freqMapForEven.begin(), freqMapForEven.end());

        std::sort(oddCount.begin(), oddCount.end(),[&](auto &a, auto &b)
        {
            return a.second > b.second;
        });

        std::sort(evenCount.begin(), evenCount.end(),[&](auto &a, auto &b)
        {
            return a.second > b.second;
        });

        int i =0;
        for( i =0;i < evenCount.size() && i < oddCount.size(); i++)
        {
            if(evenCount[i].first != oddCount[i].first)
                break;
        }
        int changeInEven = evenSize - evenCount[i].second;
        int changeInOdd = oddSize - oddCount[i].second;

        return changeInEven+changeInOdd;
    }
};

//int main(void)
//{
//    vector<int> num1 = {3,1,3,2,4,3};
////    vector<int> num2 = {1,2,2,2,2};
//    Solution().minimumOperations(num1);
//}
