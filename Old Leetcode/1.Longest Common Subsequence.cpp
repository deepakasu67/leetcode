#include<iostream>
#include<string>
#include<unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubSequence(string& text1, string& text2, int i, int j, vector<vector<int>>& dp)
    {
        if (i == text1.length() || j == text2.length())
        {
            return 0;
        }
        if (dp[i][j] != 0)
        {
            return dp[i][j];
        }
        int bothMatches = 0;
        int incrementJ = 0;
        int incrementI = 0;
        if (text1[i] == text2[j])
        {
            bothMatches += 1 + longestCommonSubSequence(text1, text2, i + 1, j + 1,dp);
        }
        else
        {
            incrementI += longestCommonSubSequence(text1, text2, i + 1, j, dp);
            incrementJ += longestCommonSubSequence(text1, text2, i , j + 1, dp);
        }
        dp[i][j] = max(bothMatches, max(incrementI, incrementJ));
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>>  dp(text1.length(),vector<int>(text2.length(),0));
        return longestCommonSubSequence(text1, text2, 0, 0, dp);
    }
};

//int main(void)
//{
//    int arr[] = { 4,-7,-3,INT_MIN,INT_MIN,-9,-3,9,-7,-4,INT_MIN,6,INT_MIN,-6,-6,INT_MIN,INT_MIN,0,6,5,INT_MIN,9,INT_MIN,INT_MIN,-1,-4,INT_MIN,INT_MIN,INT_MIN,-2 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    Solution obj;
//    obj.longestCommonSubsequence("abcde", "ace");
//}
