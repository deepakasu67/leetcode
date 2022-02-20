//
// Created by Deepak Sahu on 1/29/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original)
    {
        unordered_set<int> map(nums.begin(), nums.end());

        while(map.count(original))
        {
            original*=2;
        }
        return original;
    }
};
