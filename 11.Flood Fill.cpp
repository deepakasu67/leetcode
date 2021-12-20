#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int M, N;
public:
    void floodFillUtil(vector<vector<int>>& screen, int x, int y, int prevC, int newC)
    {
        // Base cases 
        if (x < 0 || x >= M || y < 0 || y >= N)
            return;
        if (screen[x][y] != prevC)
            return;
        if (screen[x][y] == newC)
            return;

        // Replace the color at (x, y) 
        screen[x][y] = newC;
        cout << "(" << x << "," << y << ")";

        // Recur for north, east, south and west 
        floodFillUtil(screen, x + 1, y, prevC, newC);
        floodFillUtil(screen, x - 1, y, prevC, newC);
        floodFillUtil(screen, x, y + 1, prevC, newC);
        floodFillUtil(screen, x, y - 1, prevC, newC);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& screen, int x, int y, int newC) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int prevC = screen[x][y];
        M = screen.size();
        N = screen[0].size();
        floodFillUtil(screen, x, y, prevC, newC);
        return screen;
    }
};
//int main(void)
//{
//    vector<vector<int>> image = { 
//                                  {1, 1, 1, 1},
//                                  {1, 1, 1, 1},
//                                  {1, 1, 1, 1}, 
//                                  {1, 1, 1, 1} 
//                                };
//    Solution obj;
//}