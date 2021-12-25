#include<iostream>
#include<vector>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

class Solution {
    int m, n;
public:
    void solveUtil(vector<vector<char>>& board, int row, int col)
    {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return;
        if (board[row][col] == 'X')
            return;
        if (board[row][col] == 'T')
            return;
        if (row == 0 || col == 0 || row == m - 1 || col == n - 1)
        {
            return;
        }
        else
            board[row][col] = 'T';

        solveUtil(board, row - 1, col); //north
        solveUtil(board, row + 1, col); //south
        solveUtil(board, row, col - 1); //east
        solveUtil(board, row, col + 1); //west

    }
    void solve(vector<vector<char>>& board)
    {
        fastIO
            if (board.empty())
                return;
        m = board.size();
        n = board[0].size();
        bool stop = false;
        int i, j;
        for (i = 0; i < board.size(); i++)
        {
            for (j = 0; j < board[0].size(); j++)
            {
                if (!i && board[i][j] == 'O')
                    solveUtil(board, i + 1, j);
                if (!j && board[i][j] == 'O')
                    solveUtil(board, i, j + 1);
                if (i == board.size() - 1 && board[i][j] == 'O')
                    solveUtil(board, i - 1, j);
                if (j == board[0].size() - 1 && board[i][j] == 'O')
                    solveUtil(board, i, j - 1);
            }
        }

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
            {
                if (!(!i ||
                    !j ||
                    i == board.size() - 1 ||
                    j == board[0].size() - 1))
                {
                    if (board[i][j] == 'T')
                    {
                        board[i][j] = 'O';
                    }
                    else
                        board[i][j] = 'X';
                }
            }
    }
};

//int main(void)
//{
//    /*vector<vector<char>> board = { {'X', 'X', 'X', 'X'},
//                                   {'X', 'O', 'O', 'X'},
//                                   {'X', 'O', 'X', 'X'},
//                                   {'X', 'X', 'O', 'X'} };*/
//   //vector<vector<char>> board = { {'O', 'O'},{'O', 'O'} };
//    vector<vector<char>> board = { {'X','O','O','X','X','X','O','X','O','O'},
//                                   {'X','O','X','X','X','X','X','X','X','X'},
//                                   {'X','X','X','X','O','X','X','X','X','X'},
//                                   {'X','O','X','X','X','O','X','X','X','O'},
//                                   {'O','X','X','X','O','X','O','X','O','X'},
//                                   {'X','X','O','X','X','O','O','X','X','X'},
//                                   {'O','X','X','O','O','X','O','X','X','O'},
//                                   {'O','X','X','X','X','X','O','X','X','X'},
//                                   {'X','O','O','X','X','O','X','X','O','O'},
//                                   {'X','X','X','O','O','X','O','X','X','O'} };
//    Solution obj;
//    for (int i = 0; i < board.size(); i++, cout << endl)
//        for (int j = 0; j < board[0].size(); j++)
//            cout << board[i][j] <<" ";
//    obj.solve(board);
//    cout << endl;
//    for (int i = 0; i < board.size(); i++, cout << endl)
//        for (int j = 0; j < board[0].size(); j++)
//            cout << board[i][j]<<" ";
//}