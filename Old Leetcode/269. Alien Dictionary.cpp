#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words)
    {
       vector<vector<char>> adjList(26, vector<char>());
       map<char,int> inOrder;
       int n = words.size();
       for (int i = 0; i < words.size(); i++)
       {
           for (int j = 0; j < words[i].length(); j++)
           {
               inOrder[words[i][j]] = 0;
           }
       }
       for(int i=0; i < n-1;i++)
       {
          string word1 = words[i];
          string word2 = words[i + 1];
          bool exhaustedAllChar = true;
          for(int j = 0 ; j < min(word1.length(), word2.length()); j++)
          {
              if (word1[j] != word2[j])
              {
                  adjList[word1[j] - 'a'].push_back(word2[j]);
                  inOrder[word2[j]]++;
                  exhaustedAllChar = false;
                  break;
              }
          }
          if (exhaustedAllChar == true)
          {
              if (word1.length() > word2.length())
              {
                  return "";
              }
          }
       }

       queue<char> nodeWithZeroInOrderDegree;
       for (auto it = inOrder.begin(); it != inOrder.end(); it++)
       {
           if (it->second == 0)
           {
               nodeWithZeroInOrderDegree.push(it->first);
           }
       }
       string result;
       int count = 0;
       while (!nodeWithZeroInOrderDegree.empty())
       {

            char ch = nodeWithZeroInOrderDegree.front();
            nodeWithZeroInOrderDegree.pop();
            result += ch;
            for (auto it = adjList[ch - 'a'].begin(); it != adjList[ch - 'a'].end(); it++)
            {
                if (--inOrder[*it] == 0)
                    nodeWithZeroInOrderDegree.push(*it);
            }
            count++;
       }
       return (count == inOrder.size()) ?  result : "";
    }
};
//
//int main(void)
//{
//    vector<string> words = { "abc", "ab" };
//    Solution obj;
//    cout<<obj.alienOrder(words);
//}