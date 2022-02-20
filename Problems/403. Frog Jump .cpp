//
// Created by Deepak Sahu on 12/29/21.
//

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

class Solution {
    unordered_map<string,bool> dp;
public:
    bool canCrossHelper(unordered_map<int,int>& stones, int currStone, int jump)
    {
        if(jump < 0)
            return false;
        if(!stones.count(currStone))
            return false;

        string key = to_string(currStone) + "|" + to_string(jump);
        if(stones[currStone] == stones.size() - 1)
            return true;

        if(dp.find(key) != dp.end())
            return dp[key];

        for(int next = -1 ; next <= 1; next++)
        {
            int nextStone = currStone + jump + next;
            if(nextStone != currStone)
                if(canCrossHelper(stones,nextStone, jump+ next))
                    return dp[key] = true;
        }
        return dp[key] = false;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> stonesToIdx;
        for(int i = 0 ;i < stones.size(); i++)
        {
            stonesToIdx[stones[i]] = i;
        }
       return canCrossHelper(stonesToIdx,stones[0],0);
    }
};

//int main(void)
//{
//     vector<int> stones = {0,1,3,5,6,8,12,17};
//    //vector<int> stones = {0,1,2,3,4,8,9,11};
//    //vector<int> stones = {0,2};
//    cout<<boolalpha<<Solution().canCross(stones);
//}
