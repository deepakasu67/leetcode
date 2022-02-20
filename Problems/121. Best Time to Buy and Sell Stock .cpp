//
// Created by Deepak Sahu on 1/4/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxTillNow = prices.back();
        int ans = 0;
        for(int i = prices.size() - 2; i >= 0; --i)
        {
            ans = max(ans,maxTillNow -  prices[i]);
            maxTillNow = max(maxTillNow,prices[i]);
        }
        return ans;
    }
};

//int main(void)
//{
//    vector<int> nums({1});
//    Solution().maxProfit(nums);
//}
