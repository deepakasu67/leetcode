#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        int rowA = A.size();
        int colA = A[0].size();
        int rowB = B.size();
        int colB = B[0].size();

        vector<vector<int>> result(rowA, vector<int>(colB, 0));

        unordered_map<int, unordered_map<int, int>> sparseA;
        unordered_map<int, unordered_map<int, int>> sparseB;

        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colA; j++)
            {
                if (A[i][j] != 0)
                    sparseA[i][j] = A[i][j];
            }
        }

        for (int i = 0; i < rowB; i++)
        {
            for (int j = 0; j < colB; j++)
            {
                if (B[i][j] != 0)
                    sparseB[i][j] = B[i][j];
            }
        }

        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colB; j++)
            {
                for (int k = 0; k < rowB; k++)
                {
                    if(sparseA.find(i) != sparseA.end() && sparseB.find(k) != sparseB.end())
                        result[i][j] += (sparseA[i][k] * sparseB[k][j]);
                }
            }
        }
        return result;
    }
};

//int main(void)
//{
//    //vector<vector<int>> mat1 = { {1, 0, 0},{-1, 0, 3} };
//    //vector<vector<int>> mat2 = { {7,0,0},{0,0,0},{0,0,1} };
//    vector<vector<int>> mat1 = { {1,-5} };
//    vector<vector<int>> mat2 = { {12},{-1} };
//    Solution obj;
//    obj.multiply(mat1, mat2);
//}