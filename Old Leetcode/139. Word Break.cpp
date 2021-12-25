#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isStrIsSpaceSegmented(string& s,int idx, unordered_set<string> &wordDictSet, unordered_map<int, bool> &dp)
    {
        if (idx == s.length())
        {
            return true;
        }
        if (dp.find(idx) != dp.end())
            return dp[idx];
        string prefix;
        for (int i = idx; i < s.length(); i++)
        {
            prefix += s[i];
            if (wordDictSet.find(prefix) != wordDictSet.end() && isStrIsSpaceSegmented(s, i + 1, wordDictSet, dp))
            {
                dp[idx] = true;
                return true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> dp;
        return isStrIsSpaceSegmented(s, 0, wordDictSet,dp);
    }
};

//int main(void)
//{
//    string s = "leetecode";
//    vector<string> wordDict = { "leet","code" };
//    Solution obj;
//    cout<<obj.wordBreak(s, wordDict);
//}