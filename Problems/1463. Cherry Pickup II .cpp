//
// Created by Deepak Sahu on 12/29/21.
//
#include <iostream>
#include <vector>
using namespace  std;
class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i , int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        else
            return true;
    }
    int cherryPickUpHelper(vector<vector<int>>& grid, int i , int j)
    {

        if(!isValid(grid,i,j))
            return 0;
        if(grid[i][j] < 0)
            return 0;

        int temp = grid[i][j];
        grid[i][j] = -1;
        int diagLeft = temp + cherryPickUpHelper(grid, i + 1, j-1);
        int down = temp + cherryPickUpHelper(grid, i + 1, j);
        int diagRight = temp + cherryPickUpHelper(grid, i +1, j+1);
        grid[i][j] = temp;
        int maximum =  max((diagLeft, down), diagRight);
        if(maximum == diagLeft)
        {
            if(isValid(grid,i+1,j - 1))
                grid[i + 1][j - 1] = 0;
        }
        else if(maximum == down)
        {
            if(isValid(grid, i + 1, j))
                grid[i+1][j] = 0;
        }
        else if(maximum == diagRight)
        {
            if(isValid(grid, i+1,j + 1))
                grid[i+1][j+1] = 0;
        }
        return maximum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int first = cherryPickUpHelper(grid,0,0);
        int second = cherryPickUpHelper(grid, 0, grid[0].size() - 1);
        return first + second;
    }
};
//int main(void)
//{
//    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
//    cout<<Solution().cherryPickup(grid);
//}
