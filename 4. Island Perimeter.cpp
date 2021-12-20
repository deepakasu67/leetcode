#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int north = (((i - 1 >= 0) ? (grid[i - 1][j] == 0 ? 1 : 0) : 1));
                    int south = (((i + 1 < grid.size()) ? (grid[i + 1][j] == 0 ? 1 : 0) : 1));
                    int east= (((j + 1 < grid[0].size()) ? (grid[i][j+1] == 0 ? 1 : 0) : 1));
                    int west= (((j - 1 < grid[0].size()) ? (grid[i][j - 1] == 0 ? 1 : 0) : 1));
                    perimeter += (north+south + east + west);
                }
            }
        }
        return perimeter;
    }
};

//int main(void)
//{
//    vector<vector<int>> mat = { 
//        {0,1,0,0},
//        {1,1,1,0},
//        {0,1,0,0},
//        {1,1,0,0 } 
//    };
//    Solution obj;
//    cout<<obj.islandPerimeter(mat);
//}