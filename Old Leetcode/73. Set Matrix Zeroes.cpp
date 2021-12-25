#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        bool row0 = false;
        bool col0 = false;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if (i == 0) row0 = true;
                    if (j == 0) col0 = true;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (col0) {
            for (int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
        if (row0) {
            for (int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
    }
};



//int main(void)
//{
//    vector<vector<int>> mat = { {0, 1, 2, 0},{3, 4, 5, 2},{1, 3, 1, 5} };
//    Solution().setZeroes(mat);
//}