#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid, int row, int col, int color)
    {
        if (row < 0 
            || col < 0 
            || row >= grid.size() 
            || col >= grid[0].size() 
            || grid[row][col] == 0 
            || grid[row][col] == color)
        {
            return 0;
        }
        grid[row][col] = color;
        int north = maxAreaOfIsland(grid, row - 1, col, color);
        int south = maxAreaOfIsland(grid, row + 1, col, color);
        int east = maxAreaOfIsland(grid, row, col + 1, color);
        int west = maxAreaOfIsland(grid, row, col - 1, color);
        return north + south + east + west + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int color = 2;
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    maxArea = max(maxAreaOfIsland(grid, i, j, color++), maxArea);
                }
            }
        }
        return maxArea;
    }
};

//int main(void)
//{
//    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
//                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
//                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
//                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
//                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
//                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
//                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
//    Solution obj;
//    obj.maxAreaOfIsland(grid);
//}