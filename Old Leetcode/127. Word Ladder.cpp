#include<iostream>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());

        if (wordDict.find(endWord) == wordDict.end())
            return 0;

        queue<string> q;
        int steps = 1;
        q.push(beginWord);
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string curr = q.front();
                q.pop();
                if (curr == endWord)
                    return steps;
                
                for (int i = 0; i < curr.size(); i++)
                {
                    string node = curr;
                    
                    for (int j = 0; j < 26; j++)
                    {
                        node[i] = 'a'+ j;
                        if (wordDict.count(node))
                        {
                            q.push(node);
                            wordDict.erase(node);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};

//int main(void)
//{
//    vector<string> wordList = { "hot","dot","dog","lot","log","cog"};
//    string beginWord = "hit";
//    string endWord = "cog";
//    Solution obj;
//    cout<<obj.ladderLength(beginWord, endWord, wordList);
//}