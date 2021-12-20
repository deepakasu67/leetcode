#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void subsetWithOutDup(vector<int>& nums, int idx, vector<vector<int>>& result, vector<int>& interimResult)
    {
        result.push_back(interimResult);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i == idx || nums[i] != nums[i - 1]) // i == idx -> if it is the first time then pick this number
            {
                interimResult.push_back(nums[i]);
                subsetWithOutDup(nums, i + 1, result, interimResult);
                interimResult.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> interimResult;
        subsetWithOutDup(nums, 0,result,interimResult );
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = {1,2,2};
//    Solution obj;
//    obj.subsetsWithDup(nums);
//}