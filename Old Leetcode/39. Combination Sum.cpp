#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void combinationSum(vector<int>& candidates, int target,vector<int>& currEle ,vector<vector<int>>& ans, int startIdx )
    {
        if(target == 0)
        {
            ans.push_back(currEle);
        }
        if(target < 0)
        {
            return;
        }
        for(int i = startIdx; i < candidates.size(); i++)
        {
            currEle.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], currEle, ans,i);
            currEle.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> currEle;
        combinationSum(candidates, target, currEle, ans,0);
        return ans;
    }
};

//int main(void)
//{
//    vector<int> candidates = { 2,3,6,7 };
//    Solution obj;
//    obj.combinationSum(candidates, 7);
//}