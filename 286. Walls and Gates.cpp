#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 2147483647
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms, int i, int j, int d)
    {
        if(i < 0 || j < 0 || i >= rooms.size() || j >= rooms[0].size() || rooms[i][j] < d )
        {
            return;
        }
        rooms[i][j] = d;
        wallsAndGates(rooms, i - 1, j, d + 1); //North
        wallsAndGates(rooms, i + 1, j, d + 1); //south
        wallsAndGates(rooms, i, j + 1, d + 1); //east
        wallsAndGates(rooms, i, j - 1, d + 1); //west
    }
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        for(int i = 0; i < rooms.size() ;i++)
        {
            for(int j = 0; j < rooms[i].size(); j++)
            {
                if(rooms[i][j] == 0)
                {
                    wallsAndGates(rooms, i, j, 0);
                }
            }
        }
    }
};

//int main(void)
//{
//    vector<vector<int>> rooms = {
//        {0, 2147483647, 2147483647, 0, -1, -1, 0, 0, 0, -1, -1, 0, 2147483647, 2147483647},
//        {2147483647, -1, 2147483647, -1, 2147483647, 0, -1, 2147483647, -1, 2147483647, 2147483647, -1, -1, 2147483647},
//        {0, 0, -1, 2147483647, -1, 2147483647, -1, -1, 2147483647, 0, 0, 2147483647, 0, 2147483647},
//        {-1, 0, 2147483647, -1, 0, 0, -1, 2147483647, 0, 2147483647, 0, -1, 0, -1}};
//    Solution obj;
//    obj.wallsAndGates(rooms);
//}