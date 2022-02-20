//
// Created by Deepak Sahu on 1/22/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums)
    {
        unordered_map<int, int> mpFreq;
        for(int n: nums)
        {
            mpFreq[n]++;
        }

        vector<int> result;
        for(int n : nums)
        {
            if(mpFreq.find(n)->second == 1)
            {
                if(mpFreq.count(n + 1) == 0 && mpFreq.count(n-1) == 0)
                    result.push_back(n);
            }
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = {1,3,5,3};
//    Solution().findLonely(nums);
//}
