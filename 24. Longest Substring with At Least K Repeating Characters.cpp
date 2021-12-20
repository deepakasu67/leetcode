#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k)
    {
        vector<int> charCount(26, 0);
        for(int i =0; i < s.length();i++)
        {
            charCount[s[i]-'a']++;
        }

        int i = 0;
        while (i < s.length() && charCount[s[i] - 'a'] >= k) { i++; }

        if (i == s.length())
            return s.length();

        string substr1 = s.substr(0, i);

        int lss1 = longestSubstring(substr1, k);

        while (i < s.length() && charCount[s[i] - 'a'] < k) { i++; }
        if (i == s.length())
            return lss1;

        string substr2 = s.substr(i);

        int lss2 = longestSubstring(substr2, k);

        return max(lss1, lss2);
    }
};

//int main(void)
//{
//    string str = "ababbc";
//    Solution obj;
//    cout<<obj.longestSubstring(str, 2);
//}