//
// Created by Deepak Sahu on 1/18/22.
//
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordBreakHelper(string &s, int idx, unordered_set<string>& wordDict)
    {
        if(idx == s.size())
            return {""};
        string prefix = "";
        vector<string> result;
        for(int i =idx; i < s.length(); i++)
        {
            prefix += s[i];
            if(wordDict.count(prefix))
            {
                vector<string> suffixes = (wordBreakHelper(s,i + 1, wordDict));
                for(string &str: suffixes)
                {
                    result.push_back( prefix + (str == "" ? "" : " ") + str);
                }
            }
        }
        return result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        auto result = wordBreakHelper(s,0,dict);
        return result;
    }
};

//int main(void)
//{
//    string s = "catsanddog";
//    vector<string> dict = {"cat","cats","and","sand","dog"};
//    auto result = Solution().wordBreak(s,dict);
//}
