#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//    int m, n;
//public:
//    int islandPerimeterUtil(vector<vector<int>> & grid, 
//                            vector<vector<bool>> &visited, 
//                            int x, int y)
//    {
//        if(x < 0 || y < 0 || x > m - 1 || y > n - 1)
//        {
//            return 1;
//        }
//        if(visited[x][y] == true && grid[x][y] == 1)
//        {
//            return 0;
//        }
//        visited[x][y] = true;
//        if(grid[x][y] == 1)
//        {
//            int east = islandPerimeterUtil(grid, visited, x , y + 1); //east
//            int west = islandPerimeterUtil(grid, visited, x, y - 1); //west
//            int north = islandPerimeterUtil(grid, visited, x - 1,y); //north
//            int south = islandPerimeterUtil(grid, visited, x + 1,y); //south
//            return east + west + north + south;
//        }
//        return 1;
//    }
//    int islandPerimeter(vector<vector<int>>& grid)
//    {
//        m = grid.size();
//        n = grid[0].size();
//        int perimeter = 0;
//        for(int i = 0 ;i < m ; i++)
//            for(int j = 0; j < n ; j++)
//            {
//                vector<vector<bool>> visited(m, vector<bool>(n, false));
//                if (grid[i][j] == 1)
//                {
//                    perimeter= islandPerimeterUtil(grid, visited, i, j);
//                    if (perimeter != 0)
//                        return perimeter;
//                }
//            }
//        return 0;
//    }
//};
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0;
        for(int i =0;i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    if (i + 1 < grid.size() && grid[i + 1][j] == 1) //south
                    {

                    }
                    else
                        perimeter++;
                    if(i-1 >= 0 && grid[i-1][j] == 1)// north
                    {
                        
                    }
                    else
                        perimeter++;
                    if(j -1 >= 0 && grid[i][j-1] == 1) //east
                    {
                        
                    }
                    else
                        perimeter++;
                    if(j+1 < grid[0].size() && grid[i][j+1] == 1 ) //west
                    {
                        
                    }
                    else
                        perimeter++;
                }
            }
        }
        return perimeter;
    }
};

//int main(void)
//{
//    vector<vector<int>> grid = { {0, 1, 0, 0},
//                                {1, 1, 1, 0},
//                                {0, 1, 0, 0 },
//                                {1, 1, 0, 0} };
//    Solution obj;
//    cout<<obj.islandPerimeter(grid);
//}