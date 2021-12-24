#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> numsToIdices;
    Solution(vector<int>& nums) {
        for(int i =0 ;i < nums.size(); i++)
        {
            numsToIdices[nums[i]].push_back(i);
        }
    }

    int pick(int target)
    {
    
        srand(rand());
        return numsToIdices[target][rand() % (numsToIdices[target].size())];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
