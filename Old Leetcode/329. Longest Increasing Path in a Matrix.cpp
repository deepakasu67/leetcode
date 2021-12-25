#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestIncreasingPathUtil(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>>& dp)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == -1 || prev >= matrix[i][j])
        {
            return 0;
        }
        if (dp[i][j] > -1)
        {
            return dp[i][j];
        }
        int temp = matrix[i][j];
        matrix[i][j] = -1;
        int pathFromNorth = 1 + longestIncreasingPathUtil(matrix, i - 1, j, temp, dp);
        int pathFromSouth = 1 + longestIncreasingPathUtil(matrix, i + 1, j, temp, dp);
        int pathFromWest = 1 + longestIncreasingPathUtil(matrix, i, j - 1, temp, dp);
        int pathFromEast = 1 + longestIncreasingPathUtil(matrix, i, j + 1, temp, dp);
        matrix[i][j] = temp;
        dp[i][j] = max({ pathFromNorth,pathFromEast,pathFromSouth, pathFromWest });
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int longestIncPath = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                int longestPathOfIj = longestIncreasingPathUtil(matrix, i, j, -1, dp);
                longestIncPath = max(longestPathOfIj, longestIncPath);
            }
        }
        return longestIncPath;
    }
};

//int main(void)
//{
//    vector<vector<int>> matrix = { {7, 7, 5},{2, 4, 6},{8, 2, 0} };
//    Solution obj;
//    obj.longestIncreasingPath(matrix);
//}