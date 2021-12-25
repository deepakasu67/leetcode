#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& tictocMat, char move)
    {
        // match row
        for(int i = 0 ;i < tictocMat.size(); i++)
        {
            bool all = true;
            for(int j = 0; j < tictocMat[0].size()  ;j++)
            {
                if (tictocMat[i][j] != move)
                    all = false;
            }
            if (all == true)
                return true;
        }

        //match col
        for(int i = 0; i < tictocMat.size(); i++)
        {
            bool all = true;
            for(int j = 0; j < tictocMat[0].size() ; j++)
            {
                if (tictocMat[j][i] != move)
                    all = false;
            }
            if (all == true)
                return true;
        }

        // match diagonal
        bool all = true;
        for(int i = 0 ; i < tictocMat.size(); i++)
        {
            if (tictocMat[i][i] != move)
                all = false;
        }
        if (all == true)
            return true;

        // match Anti-diagonal
        all = true;
        for (int i = tictocMat.size() - 1, j= 0; i >= 0; i--, j++)
        {
            if (tictocMat[i][j] != move)
                all = false;
        }
        if (all == true)
            return true;

        return false;
    }
    string tictactoe(vector<vector<int>>& moves)
    {
        int count = 9;
        vector<vector<char>> ticTacToeMat(3, vector<char>(3));
        char move;
        for(int i =0 ; i < moves.size() && count >=0; i++, count--)
        {
            int row = moves[i][0];
            int col = moves[i][1];

            if (i % 2 == 0)
                move = ticTacToeMat[row][col] = 'X';
            else
                move = ticTacToeMat[row][col] = 'O';

         

            if (isValid(ticTacToeMat, move))
                return i % 2 == 0 ? "A" : "B";
        }
        return count == 0 ? "Draw" : "Pending";
    }
};

//int main(void)
//{
//    vector<vector<int>> moves = { {0, 0},{1, 1},{0, 1},{0, 2},{1, 0},{2, 0} };
//    Solution obj;
//    cout<<obj.tictactoe(moves);
//}