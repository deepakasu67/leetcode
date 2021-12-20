#include<iostream>
#include<vector>

 // This is the BinaryMatrix's API interface.
 // You should not implement it, or speculate about its implementation
 class BinaryMatrix {
   public:
     int get(int row, int col);
     std::vector<int> dimensions();
 };
 

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix& binaryMatrix)
    {
        std::vector<int> lXb = binaryMatrix.dimensions();
        int result = INT_MAX;
        int R = lXb[0];
        int C = lXb[1];

        int startC = C - 1;
        int startR = 0;

        while (startC >= 0 && startR < R)
        {
            if (binaryMatrix.get(startR, startC) == 1)
            {
                result = std::min(startC, result);
                startC--;
            }
            else
            {
                startR++;
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};