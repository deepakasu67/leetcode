//
// Created by Deepak Sahu on 1/14/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, int idx, unordered_set<string> &wordDict)
    {
        if(idx == s.length())
            return true;

        string str;
        for(int i = idx; i < s.size(); i++)
        {
            str+=s[i];
            if(wordDict.count(str) && wordBreak(s,i + 1, wordDict))
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordDictionary(wordDict.begin(), wordDict.end());
        return wordBreak(s,0,wordDictionary);
    }
};
//int main(void)
//{
//    string s = "leetcode";
//    vector<string> wordDict = {"leet","code"};
//    cout<<Solution().wordBreak(s, wordDict);
//}
