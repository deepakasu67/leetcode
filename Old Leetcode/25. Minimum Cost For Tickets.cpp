#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
    int dp[1000];
public:
    Solution()
    {
        std::fill_n(dp, 1000, INT_MAX);
    }
    int minCostUtil(vector<int>& days, vector<int>& costs, int idx)
    {
        if(idx == days.size())
        {
            return 0;
        }
        if (dp[idx] != INT_MAX)
            return dp[idx];
        int costOfOneDay = costs[0];
        costOfOneDay += minCostUtil(days, costs, idx + 1);

        int costOf7Days = costs[1];
        int currDay = days[idx];
        int expirydate = days[idx] + 7 - 1;
        int nextDayIdx = upper_bound(days.begin(), days.end(), expirydate) - days.begin();
        costOf7Days += minCostUtil(days, costs, nextDayIdx);

        int costOf30Days = costs[2];
        expirydate = days[idx] + 30 - 1;
        nextDayIdx = upper_bound(days.begin(), days.end(), expirydate) - days.begin();
        costOf30Days += minCostUtil(days, costs, nextDayIdx);

        int minimumOfAllDayPasses = min(min(costOfOneDay, costOf7Days), costOf30Days);
        dp[idx] = min(dp[idx], minimumOfAllDayPasses);
        return dp[idx];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int minimum = minCostUtil(days, costs, 0);
        return minimum;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> costs = { 9, 38, 134 };
//    vector<int> days = { 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 24, 25, 27, 28, 29, 30, 31, 34, 37, 38, 39, 41, 43, 44, 45, 47, 48, 49, 54, 57, 60, 62, 63, 66, 69, 70, 72, 74, 76, 78, 80, 81, 82, 83, 84, 85, 88, 89, 91, 93, 94, 97, 99 };
//    obj.mincostTickets(days,costs);
//}
