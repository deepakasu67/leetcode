//
// Created by Deepak Sahu on 12/25/21.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace  std;


class Solution {
public:
    vector<long long> getDistances(vector<int>& arr)
    {
        vector<long long> ans;
        unordered_map<int, vector<int>> freqMap;
        for(int i =0 ; i  < arr.size(); i++)
        {
            freqMap[arr[i]].push_back(i);
        }
        for(int i =0; i < arr.size(); i++) {
            auto it = freqMap[arr[i]];
            long long sum = 0;
            for(int j = 0; j < it.size(); j++)
            {
                sum += abs(i - it[j]);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
//int main(void)
//{
//    vector<int> arr = {10,5,10,10};
//    Solution().getDistances(arr);
//}