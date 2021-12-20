#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        for(int i =0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if (i - 1 >= 0 && j - 1 >= 0 && matrix[i - 1][j - 1] != matrix[i][j]) //just check top-left cell
                    return false;
            }
        }
        return true;
    }
};

//int main(void)
//{
////    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
//    vector<vector<int>> matrix = { {1,2},{2,2}};
//    Solution obj;
//    cout<<obj.isToeplitzMatrix(matrix);
//}