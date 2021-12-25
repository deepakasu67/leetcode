#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<unordered_set<int>> boxes(9, unordered_set<int>());

        for (int i = 0; i < board.size(); i++)
        {
            vector<bool> isPresent(10, false);
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (board[i][j] > '9')
                    return false;
                if (isPresent[board[i][j] - '0'] == true)
                    return false;

                int boxesIdx = (i / 3) * 3 + j / 3;

                if (boxes[boxesIdx].find(board[i][j] - '0') != boxes[boxesIdx].end())
                    return false;

                boxes[boxesIdx].insert(board[i][j] - '0');
                isPresent[board[i][j] - '0'] = true;
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            vector<bool> isPresent(10, false);
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (board[j][i] > '9')
                    return false;
                if (isPresent[board[j][i] -'0'] == true)
                    return false;
                isPresent[board[j][i] - '0'] = true;
            }
        }




        return true;
    }
};

//int main(void)
//{
//    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}
//        , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
//        , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
//        , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
//        , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
//        , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
//        , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
//        , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
//        , {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
//
//    Solution obj;
//    cout << obj.isValidSudoku(board);
//}