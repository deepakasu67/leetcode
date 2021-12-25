#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int returnTheSizeIdxOfValidIsland(vector<vector<int>>& grid, int row, int col)
    {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0)
            return 0;
        return grid[row][col];
    }
    int sizeOfIsland(vector<vector<int>>& grid, int mark, int row, int col)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0 || grid[row][col] == mark) 
            return 0;

        grid[row][col] = mark;

        int north = sizeOfIsland(grid, mark, row - 1, col);
        int south = sizeOfIsland(grid, mark, row + 1, col);
        int east = sizeOfIsland(grid, mark, row, col + 1);
        int west = sizeOfIsland(grid, mark, row, col - 1);
        int size = 1 + north + south + east + west;
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) 
    {
        int maxSizeOfIslands = 0;
        vector<int> sizes = { 0,0 };
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    sizes.push_back(sizeOfIsland(grid, sizes.size(), i, j));
                    maxSizeOfIslands = max(sizes.back(), maxSizeOfIslands);
                }
            }
        }
        set<int> uniqueSizeIndices;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    int northernIslandSizeIdx = returnTheSizeIdxOfValidIsland(grid, i - 1, j);
                    int southernIslandSizeIdx = returnTheSizeIdxOfValidIsland(grid, i + 1, j);
                    int easternIslandSizeIdx = returnTheSizeIdxOfValidIsland(grid, i, j + 1);
                    int westernIslandSizeIdx = returnTheSizeIdxOfValidIsland(grid, i, j - 1);
                    uniqueSizeIndices.insert({ northernIslandSizeIdx, southernIslandSizeIdx,easternIslandSizeIdx,westernIslandSizeIdx });
                    int totalSizeOfIslands = 1;
                    for (auto& uniqueSizeIdx : uniqueSizeIndices)
                    {
                        totalSizeOfIslands += sizes[uniqueSizeIdx];
                    }
                    maxSizeOfIslands = max(maxSizeOfIslands, totalSizeOfIslands);
                    uniqueSizeIndices.clear();
                }
            }
        }
        return maxSizeOfIslands;
    }
};

//int main(void)
//{
//    Solution obj;
//    
//    vector<vector<int>> grid = { {1, 0, 1},{0, 0, 0},{0, 1, 1} };
//    cout<<obj.largestIsland(grid);
//}