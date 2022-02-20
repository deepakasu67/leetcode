//
// Created by Deepak Sahu on 2/17/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> ans;
public:
    void combinationSum(vector<int>& candidates, int target, vector<int>& currentCand, int idx)
    {
        if(target < 0)
            return;
        if(target == 0)
        {
            ans.push_back(currentCand);
            return;
        }

        for(int i =idx;i < candidates.size(); i++)
        {
            currentCand.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], currentCand, i);
            currentCand.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> currentCand;
        combinationSum(candidates,target,currentCand,0 );
        return ans;
    }
};
//
//int main(void)
//{
//    vector<int> candidates = {2,3,6,7};
//    int target = 7;
//    Solution().combinationSum(candidates, target);
//}
