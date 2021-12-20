#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    int m, n;
public:
    bool existUtil(vector<vector<char>>& board, int idx, string& word, int x, int y)
    {
        if (idx == word.size())
        {
            return true;
        }
        if (x < 0 || y < 0 || x >= m || y >= n)
        {
            return false;
        }
        char temp = board[x][y];
        if (board[x][y] != '*' && board[x][y] == word[idx])
        {
            board[x][y] = '*';
            if (
                (existUtil(board, idx + 1, word, x, y - 1)) || //east
                (existUtil(board, idx + 1, word, x, y + 1)) || //west
                (existUtil(board, idx + 1, word, x - 1, y)) || //north
                (existUtil(board, idx + 1, word, x + 1, y))   //south
                )
            {
                return true;
            }
        }
        board[x][y] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        m = board.size();
        n = board[0].size();
        if (word.empty())
            return false;
        if (board.empty())
            return false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    auto newBoard = board;
                    if (existUtil(newBoard, 0, word, i, j) == false)
                        continue;
                    else
                        return true;
                }
            }
        }
        return false;
    }
};
//int main(void)
//{
//    vector<vector<char>> board = { {'A', 'B', 'C', 'E'}, { 'S', 'F', 'E', 'S' }, { 'A', 'D', 'E', 'E' } };
//    Solution obj;
//    cout << obj.exist(board, "ABCESEEEFS");
//    return 0;
//}