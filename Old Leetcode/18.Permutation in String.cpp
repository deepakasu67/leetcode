#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
class Solution {

public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

    }
    bool isAnagram(array<int, 26> subStringCount, array<int, 26> patternsCount, string pattern)
    {
        for (int i = 0; i < pattern.length(); i++)
        {
            if (subStringCount[pattern[i] - 'a'] != patternsCount[pattern[i] - 'a'])
                return false;
        }
        return true;
    }
    bool findAnagrams(string s, string p) {
        array<int, 26> patternsCount = { 0 }, subStringCount = { 0 };
        int stringsLength = s.length();
        int patternsLength = p.length();

        vector<int> result;
        if (s.empty() || p.empty())
            return false;
        if (stringsLength < patternsLength)
            return false;
        for_each(begin(p), end(p), [&patternsCount](char ch) {
            patternsCount[ch - 'a']++;
            });

        for (int i = 0; i < patternsLength; i++)
        {
            subStringCount[s[i] - 'a']++;
        }
        for (int i = 0; i <= stringsLength - patternsLength;)
        {
            if (isAnagram(subStringCount, patternsCount, p))
            {
                return true;
            }
            i++;
            if (i > stringsLength - patternsLength)
                break;
            subStringCount[s[i - 1] - 'a']--;
            subStringCount[s[i + patternsLength - 1] - 'a']++;
        }
        return false;
    }

    bool checkInclusion(string s1, string s2)
    {
        return findAnagrams(s2, s1);
    }

};

////int main(void)
////{
////    Solution obj;
////    cout<<obj.checkInclusion("", "eidboaoo");
//}