//
// Created by Deepak Sahu on 12/27/21.
//

#include<iostream>
#include<vector>
using namespace  std;

class Solution {
    vector<vector<int>> dp;
public:
    int miniPathSumHelper(vector<vector<int>>& grid, int i, int j)
    {
        if(i >= grid.size() || j >= grid[0].size())
        {
            return INT_MAX;
        }
        if(dp[i][j] != 0)
            return dp[i][j];
        if(i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return grid[i][j];
        }
        int right =   miniPathSumHelper(grid, i, j + 1) ;
        int down = miniPathSumHelper(grid, i + 1, j );
        return dp[i][j] = grid[i][j] + min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        dp.resize(grid.size(), vector<int>(grid[0].size(),0));
        return miniPathSumHelper(grid, 0,0);
    }
};

//int main(void)
//{
//    vector<vector<int>> grid = {{1,3,1},{1,5,1}, {4,2,1}};
//    cout<<Solution().minPathSum(grid);
//}