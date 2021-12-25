#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countUniquePaths(vector<vector<int>> &countPathMat, int i, int j)
    {
        if (i >= countPathMat.size() || j >= countPathMat[0].size())
            return 0;
        if (i == countPathMat.size() - 1 && j == countPathMat[0].size() - 1)
            return (countPathMat[i][j] = 1);

        if (countPathMat[i][j] > 0)
        {
            return countPathMat[i][j];
        }
        int down = countUniquePaths(countPathMat, i + 1, j);
        int right = countUniquePaths(countPathMat, i , j+1);
        countPathMat[i][j] += (down + right);
        return countPathMat[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> countPathMat(m, vector<int>(n));
        return countUniquePaths(countPathMat, 0, 0);
    }
};

//int main(void)
//{
//    cout<<Solution().uniquePaths(3, 7);
//}