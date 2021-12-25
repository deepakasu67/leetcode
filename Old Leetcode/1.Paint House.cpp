#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs, int prevColIdx, int row)
    {
        if(row == costs.size())
        {
            return INT_MAX;
        }
        int minCostFromCurrentCell = INT_MAX;
        for(int i = 0; i < costs[row].size(); i++)
        {
            if(i != prevColIdx)
            {
                minCostFromCurrentCell = min(minCostFromCurrentCell, minCost(costs, i, row + 1));
            }
        }
        return (prevColIdx < 0 ? 
            minCostFromCurrentCell : (minCostFromCurrentCell == INT_MAX ?
                                             0 + costs[row][prevColIdx] : minCostFromCurrentCell + costs[row][prevColIdx]));
    }
    int minCost(vector<vector<int>>& costs)
    {
        return minCost(costs, -1, 0);
    }
};

//int main(void)
//{
//    vector<vector<int>> cost = { {17, 2, 17},{16, 16, 5},{14, 3, 19} };
//    Solution obj;
//    cout<<obj.minCost(cost);
//}