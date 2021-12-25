#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascalNumber(2, vector<int>(rowIndex + 1));
        pascalNumber[0][0] = 1;
        if(rowIndex == 0)
            return pascalNumber[rowIndex % 2];

        pascalNumber[1][0] = 1;
        pascalNumber[1][1] = 1;


        for (int i = 2; i <= rowIndex; i++)
        {
            pascalNumber[i % 2][i] = 1;
            for (int j = 1; j < i; j++)
            {
                pascalNumber[i % 2][j] =  pascalNumber[(i + 1) % 2][j - 1] + pascalNumber[(i + 1) % 2][j];
            }
        }
        return pascalNumber[rowIndex % 2];
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.getRow(0);
//}