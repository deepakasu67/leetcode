#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isValidPosition(vector<vector<bool>>& queens, int row, int col)
    {
        //check col
        for(int i = row - 1; i >= 0 ; i--)
        {
            if(true == queens[i][col])
            {
                return false;
            }
        }

        //check left-diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (true == queens[i][j])
                return false;
        }

        //check right-diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < queens[0].size(); i--, j++)
        {
            if (true == queens[i][j])
                return false;
        }
        return true;
    }
    vector<string> constructAns(vector<vector<bool>>& queenColumns)
    {
        vector<string> result;
        for(int i =0 ; i < queenColumns.size(); i++)
        {
            string temp;
            for(int j = 0; j < queenColumns[i].size(); j++)
            {
                if(queenColumns[i][j] == true)
                {
                    temp += 'Q';
                }
                else
                {
                    temp += '.';
                }
            }
            result.push_back(temp);
        }
        return result;
    }

    void solveNQueen(int n, int row, vector<vector<string>>& ans, vector<vector<bool>>& queens)
    {
        if(n == row )
        {
            ans.push_back(constructAns(queens));
            return;
        }
        if(row >= n)
        {
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(isValidPosition(queens, row, i))
            {
                queens[row][i] = true;
                solveNQueen(n, row + 1, ans, queens);
                queens[row][i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<bool>> queenMat(n, vector<bool>(n, false));
        vector<vector<string>> ans;
        solveNQueen(n, 0, ans, queenMat);
        return ans;
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.solveNQueens(1);
//}