//
// Created by Deepak Sahu on 1/29/22.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums)
    {
        int numberOfOnes = count(nums.begin(),nums.end(),1);
        int onesCount = 0;
        int zeroesCount = 0;
        map<int,vector<int>> intermediateResult;
        intermediateResult[numberOfOnes].push_back(0);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zeroesCount++;
            if(nums[i] == 1)
                onesCount++;

            int indicesScores = zeroesCount + (numberOfOnes - onesCount);
            intermediateResult[indicesScores].push_back( i+1);
        }
        return intermediateResult.rbegin()->second;
    }
};
//
//int main(void)
//{
//    vector<int> nums = {0,0,1,0};
//    Solution().maxScoreIndices(nums);
//}
//

