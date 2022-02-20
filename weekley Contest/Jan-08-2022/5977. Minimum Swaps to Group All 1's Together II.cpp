//
// Created by Deepak Sahu on 1/8/22.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums)
    {
        int ones = 0;
        for(int i =0; i < nums.size(); i++)
        {
            if(nums[i]==1)
                ones++;
        }

        nums.insert(nums.end(), nums.begin(), nums.end());
        int l =0;
        int count = 0;
        for(int r = 0;r < nums.size(); r++ )
        {

        }
    }
};
