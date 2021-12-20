#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int areaOfIsland(vector<vector<int>>& grid, int i , int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0)
        {
            return 0;
        }
        grid[i][j] = -1;
        int north = areaOfIsland(grid, i - 1, j);
        int south = areaOfIsland(grid, i + 1, j);
        int east = areaOfIsland(grid, i, j + 1);
        int west = areaOfIsland(grid, i, j - 1);

        int area = 1 + north + south + east + west;
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxArea = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    maxArea = max(maxArea, areaOfIsland(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};

//int main(void)
//{
//    vector<vector<int>> grid = {
//        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
//        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
//        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
//    };
//    Solution obj;
//    obj.maxAreaOfIsland(grid);
//}