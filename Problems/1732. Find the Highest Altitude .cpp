//
// Created by Deepak Sahu on 1/7/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        int maxGain = 0;
        int afterGain = 0;
        for(int i =0; i < gain.size(); i++)
        {
            afterGain = afterGain + gain[i];
            maxGain = max(maxGain, afterGain);
        }
        return maxGain;
    }
};

//int main(void)
//{
////    vector<int> nums = {-5,1,5,0,-7};
//    vector<int> nums = {-4,-3,-2,-1,4,3,2};
//    Solution().largestAltitude(nums);
//}

