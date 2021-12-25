#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices)
    {
        long long increasingCount = 1;
        long long ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if ((prices[i - 1] - prices[i]) != 1)
            {
                ans += (increasingCount * (increasingCount - 1) / 2);
                increasingCount = 0;
            }
            increasingCount++;
        }
        return ans + prices.size();
    }
};

//int main()
//{
//    vector<int> prices = { 4,1,5,2,6,2 };
//    Solution().getDescentPeriods(prices);
//}