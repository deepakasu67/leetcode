#include<iostream>
#include<vector>
#include<string>
#include<set>
#include <unordered_set>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

class Solution {
    int m, n;
public:
    bool isWordPresent(vector<vector<char>>& board, string& words, int x, int y, int idx)
    {
        if (idx == words.size())
        {
            return true;
        }
        if (x < 0 || y < 0 || x >= m || y >= n)
        {
            return false;
        }
        int temp = board[x][y];

        if (board[x][y] != '*' && words[idx] == board[x][y])
        {
            board[x][y] = '*';
            if (
                (isWordPresent(board, words, x, y - 1, idx + 1)) || //east
                (isWordPresent(board, words, x, y + 1, idx + 1)) || //west
                (isWordPresent(board, words, x - 1, y, idx + 1)) || //north
                (isWordPresent(board, words, x + 1, y, idx + 1))   //south
                )
            {
                return true;
            }
        }
        board[x][y] = temp;

        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        fastIO;
        m = board.size();
        n = board[0].size();
        vector<string> result;
        int k = 0;
        for (int k = 0; k < words.size(); k++)
        {
            //if (result.find(words[k]) != result.end()) continue;
            bool stop = false;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == words[k][0])
                    {
                        auto newBoard = board;
                        bool found = isWordPresent(newBoard, words[k], i, j, 0);
                        if (found == true)
                        {
                            result.emplace_back(words[k]);
                            stop = true;
                            break;
                        }
                    }
                }
                if (stop == true)
                {
                    break;
                }
            }
        }
        return  result;
    }
};

//int main(void)
//{
//    //vector<vector<char>> board = {
//    //    {'o', 'a', 'a', 'n' },
//    //    {'e', 't', 'a', 'e' },
//    //    {'i', 'h', 'k', 'r' },
//    //    {'i', 'f', 'l', 'v' }
//    //};
//    /*vector<vector<char>> board = { {'a','b'},
//                                   {'c','d'} };*/
//    vector<vector<char>> board = { {'b', 'a', 'a', 'b', 'a', 'b'},
//                                   {'a', 'b', 'a', 'a', 'a', 'a'},
//                                   {'a', 'b', 'a', 'a', 'a', 'b'},
//                                   {'a', 'b', 'a', 'b', 'b', 'a'},
//                                   {'a', 'a', 'b', 'b', 'a', 'b'},
//                                   {'a', 'a', 'b', 'b', 'b', 'a'},
//                                   {'a', 'a', 'b', 'a', 'a', 'b'} };
//    /*vector<string> words = { "oath","pea","eat","rain", "aaae" };*/
//    //vector<string> words = { "ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb" };
//
//    vector<string> words = { "bbaabaabaaaaabaababaaaaababb", 
//                             "aabbaaabaaabaabaaaaaabbaaaba", 
//                             "babaababbbbbbbaabaababaabaaa", 
//                             "bbbaaabaabbaaababababbbbbaaa", 
//                             "babbabbbbaabbabaaaaaabbbaaab", 
//                             "bbbababbbbbbbababbabbbbbabaa",
//                             "babababbababaabbbbabbbbabbba", 
//                             "abbbbbbaabaaabaaababaabbabba",
//                             "aabaabababbbbbbababbbababbaa",
//                             "aabbbbabbaababaaaabababbaaba", //
//                             "ababaababaaabbabbaabbaabbaba", //
//                             "abaabbbaaaaababbbaaaaabbbaab", //
//                             "aabbabaabaabbabababaaabbbaab", 
//                             "baaabaaaabbabaaabaabababaaaa", 
//                             "aaabbabaaaababbabbaabbaabbaa", 
//                             "aaabaaaaabaabbabaabbbbaabaaa", 
//                             "abbaabbaaaabbaababababbaabbb", 
//                             "baabaababbbbaaaabaaabbababbb", 
//                             "aabaababbaababbaaabaabababab", 
//                             "abbaaabbaabaabaabbbbaabbbbbb", 
//                             "aaababaabbaaabbbaaabbabbabab", 
//                             "bbababbbabbbbabbbbabbbbbabaa",
//                             "abbbaabbbaaababbbababbababba",
//                              "bbbbbbbabbbababbabaabababaab", 
//                              "aaaababaabbbbabaaaaabaaaaabb", 
//                             "bbaaabbbbabbaaabbaabbabbaaba",
//                             "aabaabbbbaabaabbabaabababaaa", 
//                            "abbababbbaababaabbababababbb", 
//                            "aabbbabbaaaababbbbabbababbbb", 
//                            "babbbaabababbbbbbbbbaabbabaa" };
//    Solution obj;
//    obj.findWords(board, words);
//}