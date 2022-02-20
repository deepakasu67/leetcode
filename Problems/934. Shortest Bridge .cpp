//
// Created by Deepak Sahu on 1/6/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

class Solution {
    unordered_set<pair<int, int>, pair_hash> perimeter;
    unordered_map<string, int> dp;
public:
    bool isValidMove(vector<vector<int>> &grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return false;
        return true;
    }

    void colorTheGraph(vector<vector<int>> &grid, int i, int j)
    {
        if(!isValidMove(grid, i, j) || grid[i][j] == 2)
            return;

        if(grid[i][j] == 0) {
            perimeter.insert({i,j});
            return;
        }

        grid[i][j] = 2;

        colorTheGraph(grid, i - 1, j ); //north
        colorTheGraph(grid, i + 1 , j ); //south
        colorTheGraph(grid, i , j + 1 ); //east
        colorTheGraph(grid, i , j - 1 ); //west
    }

    int shortestBridge(vector<vector<int>>& grid)
    {
        for(int i =0; i < grid.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < grid[i].size(); ++j) {

                if(grid[i][j] == 1)
                {
                    found = true;
                    colorTheGraph(grid,i,j);
                    break;
                }

            }
            if(found == true)
                break;
        }

        int shortestBridge = INT_MAX;

        queue<pair<int,int>> Q;
        for(auto it = perimeter.begin(); it!=perimeter.end(); it++)
        {
            Q.push({it->first,it->second});
        }

        int depth = 0;
        while(Q.size() > 0) {
            int N = Q.size();
            ++depth;
            while (N--) {
                const auto node = Q.front();
                Q.pop();
                int dir[] = {-1, 0, 1, 0, -1};
                for (int i = 0; i < 4; ++i) {
                    int X = node.first + dir[i];
                    int Y = node.second + dir[i + 1];
                    if (isValidMove(grid, X, Y)) {
                        if (grid[X][Y] == 1) return depth;
                        if (grid[X][Y] == 0) {
                            Q.push({X, Y});
                            grid[X][Y] = -1;
                        }
                    }
                }
            }
        }

    }
};

//int main(void)
//{
////    vector<vector<int>> grid = {
////            {1,1,1,1,1},
////            {1,0,0,0,1},
////            {1,0,1,0,1},
////            {1,0,0,0,1},
////            {1,1,1,1,1}
////    };
////  vector<vector<int>> grid = {{0,1},{1,0}};
//  vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
////    vector<vector<int>> grid = {{1,1,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
//    cout<<Solution().shortestBridge(grid);
//}