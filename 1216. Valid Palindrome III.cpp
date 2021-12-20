#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumRemovalToMakePalindrome(string& s, int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
        {
            return 0;
        }
        if (i == j - 1)
        {
            return s[i] != s[j];
        }
        if (dp[i][j] != 0)
            return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = minimumRemovalToMakePalindrome(s, i + 1, j - 1, dp);

        int removeJ = minimumRemovalToMakePalindrome(s, i, j - 1, dp);
        int removeI = minimumRemovalToMakePalindrome(s, i + 1, j, dp);
        return dp[i][j] =  1 + min(removeI, removeJ);
    }
    bool isValidPalindrome(string s, int k) 
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int mra = minimumRemovalToMakePalindrome(s, 0, s.length() - 1,dp);
        return mra <= k;
    }
};
//
//int main(void)
//{
//    string str = "abcdeca";
//    Solution obj;
//    cout<<obj.isValidPalindrome(str, 2);
//}