#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreakUtil(string s, unordered_set<string>& wordDict, int idx, unordered_map<int, vector<string>> &dp)
    {
        vector<string> sufix;
        string word;
        
        if (idx == s.length())
            sufix.push_back("");
        if (dp.find(idx) != dp.end())
            return dp[idx];
        for(int i = idx; i < s.size();i++)
        {
            word += s[i];
            if (wordDict.find(word) != wordDict.end())
            {
                vector<string> tmp = wordBreakUtil(s, wordDict, i + 1,dp);
                    for (string t : tmp)
                        sufix.push_back(word + (t == ""? "" : " " )+t);
            }
        }

        dp[idx] = sufix;
        return sufix;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> dp;
        string sentence;
       auto result = wordBreakUtil(s, wordDictSet, 0,dp);
       return result;
    }
};

//int main(void)
//{
//    vector<string> wordDict = { "apple", "pen", "applepen", "pine", "pineapple" };
//    Solution obj;
//    obj.wordBreak("pineapplepenapple", wordDict);
//}