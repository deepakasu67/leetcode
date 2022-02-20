//
// Created by Deepak Sahu on 2/13/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());

        for(int n: nums)
        {
            auto tempResult = result;
            for(auto intermediateResult: tempResult)
            {
                if(intermediateResult.empty())
                {
                    result.push_back(vector<int>(1,n));
                    continue;
                }
                vector<int> temp = intermediateResult;
                temp.push_back(n);
                result.push_back(temp);
            }
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> nums = {1,2,3};
//    Solution().subsets(nums);
//}
