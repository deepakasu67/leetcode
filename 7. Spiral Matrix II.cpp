#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &mat, int i, int j, int currCount,int direction)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != 0)
        {
            return;
        }
        mat[i][j] = currCount ;
        if (direction == 1)
        {
            dfs(mat, i, j + 1, currCount + 1, 1); //east
            direction = 2;
        }
        if (direction == 2)
        {
            dfs(mat, i + 1, j, currCount + 1, 2); //south
            direction = 3;
        }
        if (direction == 3)
        {
            dfs(mat, i, j - 1, currCount + 1, 3); //west
            direction = 4;
        }
        if (direction == 4)
        {
            dfs(mat, i - 1, j, currCount + 1, 4); //north
            //reached north pole then start exploring east
            dfs(mat, i, j + 1, currCount + 1, 1); //east
        }
    }
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        dfs(matrix, 0, 0, 1,1);
        return matrix;
    }
};
//
//int main(void)
//{
//    Solution obj;
//    obj.generateMatrix(4);
//}