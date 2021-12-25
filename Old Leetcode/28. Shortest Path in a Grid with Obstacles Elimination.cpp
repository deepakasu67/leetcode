#include<iostream>
#include<vector>
#include <algorithm>
#include<string>
#include <map>
#include<queue>
using namespace std;

class Solution {
public:
    int shortestPathRemovingObstacles(vector<vector<int>>& grid, int k, int i, int j, map<string, int> &dp)
    {
        string key = to_string(i) + "|" + to_string(j);
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 2 )
            return -1;

        if (i == grid.size() - 1 && j == grid[0].size() - 1 && k >= 0 && (grid[i][j] == 0))
            return 1;


        if (k <= 0 && grid[i][j] == 1)
            return -1;
        
        if (dp.find(key) != dp.end())
            return dp[key];

        if (grid[i][j] == 1)
            k = k - 1;
        int temp = grid[i][j];
        grid[i][j]= 2;
        int north = shortestPathRemovingObstacles(grid, k, i - 1, j,dp);
        int south = shortestPathRemovingObstacles(grid, k, i + 1, j,dp);
        int east = shortestPathRemovingObstacles(grid, k, i, j + 1 ,dp);
        int west = shortestPathRemovingObstacles(grid, k, i, j - 1 ,dp);
        grid[i][j] = temp;
        if (temp == 1)
            k++;
        if (north == -1)
            north = INT_MAX;
        if (south == -1)
            south = INT_MAX;
        if (east == -1)
            east = INT_MAX;
        if (west == -1)
            west = INT_MAX;

        int shortestPath = min(initializer_list<int>{north,south, east, west});
        dp[key] =  shortestPath == INT_MAX ? -1: 1+shortestPath;
        return dp[key];
    }

    bool isValid(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &visited, int k)
    {
        return (
                  (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
                  || (k <= 0 && grid[i][j]==1) 
                  || visited[i][j] == true);
    }

    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        visited[0][0] = true;
        int pathLength = 0;
        while (!q.empty())
        {
            auto node = q.front();
            int i = node.first;
            int j = node.second;
            q.pop();
            
            if (i == grid.size() - 1 && j == grid[0].size() - 1)
                return pathLength;

            //north
            if (!isValid(i - 1, j, grid, visited, k))
            {
                if (grid[i - 1][j] == 1)
                    k--;
                visited[i - 1][j] = true;
                q.push({ i -1 ,j });
            }
            //south
            if (!isValid(i + 1, j, grid, visited, k))
            {
                if (grid[i + 1][j] == 1)
                    k--;
                visited[i + 1][j] = true;
                q.push({ i + 1,j });
            }
            //east
            if (!isValid(i, j + 1, grid, visited, k))
            {
                if (grid[i][j + 1] == 1)
                    k--;
                visited[i][j + 1] = true;
                q.push({ i,j + 1 });
            }
            //west
            if (!isValid(i, j - 1, grid, visited, k))
            {
                if (grid[i][j - 1] == 1)
                    k--;
                visited[i][j - 1] = true;
                q.push({ i,j - 1 });
            }
            pathLength++;
        }
        return -1;
    }
};

//int main(void)
//{
//    vector<vector<int>> mat =
//    //{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
//    { 
//        {0, 1, 0, 1},
//        {0, 1, 0, 0},
//        {0, 0, 1, 0},
//        {1, 0, 0, 1},
//        {0, 1, 0, 0} 
//    };
//
//   /* { {1,1,1},
//        {1,0,1},
//        {1,1,1} };*/
//    /*  { {0, 0, 0},
//        {1, 1, 0},
//        {0, 0, 0},
//        {0, 1, 1},
//        {0, 0, 0} };*/
//
//    Solution obj;
//    cout<<obj.shortestPath(mat, 5);
//}