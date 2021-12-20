#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isABCPresent(vector<int>& charFreq)
    {
        if (charFreq[0] > 0 && charFreq[1] > 0 && charFreq[2] > 0)
            return true;
        return false;
    }
    int numOfSubstrings(string& s, int i, int j, vector<vector<bool>>& dp, vector<int>& charFreq)
    {
        if (j-i+ 1 < 3 ||!isABCPresent(charFreq))
        {
            return 0;
        }
        if (dp[i][j] == true || dp[j][i] == true)
            return 0;
        dp[i][j] = true;
        dp[j][i] = true;
        charFreq[s[i] - 'a']--;
        int leftReduction = numOfSubstrings(s, i + 1, j, dp, charFreq);
        charFreq[s[i] - 'a']++;

        charFreq[s[j] - 'a']--;
        int rightReduction = numOfSubstrings(s, i, j-1, dp, charFreq);
        charFreq[s[j] - 'a']++;

        int numOfSubstring= 1 + leftReduction + rightReduction;
        return numOfSubstring;
    }
    int numberOfSubstrings(string s) 
    {
        int n = s.length();

        vector<int>count = { 0, 0, 0 };
        int i = 0, j = 0, res = 0, ans = 0;

        for (i = 0; i < n; i++) {
            count[s[i] - 'a']++;     /* have some hashmap or counter */

            /* Loop inside for to reduce the window size based on constraint */
            while (j < n && count[0] && count[1] && count[2]) {
                ans++;
                count[s[j] - 'a']--;
                j++;
            }

            /* Count number of substrings */
            res += ans;
        }

        return res;

    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.numberOfSubstrings("abcabc");
//}
