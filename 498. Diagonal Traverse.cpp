#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return {};
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        vector<int> result(rowSize * colSize);
        int resultIdx = 0;
        bool goingUp = true;

        int currRow = 0, currCol = 0;

        while(currRow < rowSize && currCol < colSize)
        {
            if(goingUp == true)
            {
                result[resultIdx++] = matrix[currRow][currCol];
                if (currCol == colSize-1)
                {
                    currRow++;
                    goingUp = false;
                }
                else if(currRow == 0)
                {
                    currCol++;
                    goingUp = false;
                }
                else
                {
                    currRow--;
                    currCol++;
                }
            }
            else
            {
                result[resultIdx++] = matrix[currRow][currCol];
                if(currRow == rowSize-1)
                {
                    currCol++;
                    goingUp = true;
                }
                else if(currCol == 0)
                {
                    currRow++;
                    goingUp = true;
                }
                else
                {
                    currRow++;
                    currCol--;
                }
            }
        }
        return result;
    }
};
//int main(void)
//{
//    vector<vector<int>> matrix = { { 1, 2, 3},
//                                    {4, 5, 6},
//                                    {7, 8, 9} };
//    Solution obj;
//    obj.findDiagonalOrder(matrix);
//}