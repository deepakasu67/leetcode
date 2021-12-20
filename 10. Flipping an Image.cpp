#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        //reverse a vector
        for(int i = 0 ; i < A.size(); i++)
        {
            reverse(A[i].begin(), A[i].end());
        }

        //invert a bit
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[i].size();j++)
            {
                A[i][j] = !A[i][j];
            }
        }
        return A;
    }
};
//int main(void)
//{
//    vector<vector<int>> mat = { {1, 1, 0},{1, 0, 1},{0, 0, 0}};
//    Solution obj;
//    obj.flipAndInvertImage(mat);
//}