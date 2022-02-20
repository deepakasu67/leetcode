//
// Created by Deepak Sahu on 1/22/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int countElements(vector<int>& nums) {

        map<int, int> mp;
        for(int i =0;i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        int count = 0;
        int result = 0;
        for(auto it = ++mp.begin(); it!= --mp.end(); it++)
        {
            count += it->second;
        }
        return count;
    }
};

//int main(void)
//{
//    vector<int> nums = {11,7,2,15};
//    cout<<Solution().countElements(nums);
//
//}