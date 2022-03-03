//
// Created by Deepak Sahu on 3/2/22.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int j =0;
        int matchedChars = 0;
        for(int i =0 ;i < s.length(); i++)
        {
            for(; j < t.length();j++)
            {
                if(s[i] == t[j])
                {
                    matchedChars++;
                    j++;
                    break;
                }
            }
        }
        return matchedChars == s.size();
    }
};

//int main(void)
//{
//    string s = "aaaaaa" ;
//    string t = "bbaaaa";
//    cout<<boolalpha;
//    cout<<Solution().isSubsequence(s,t);
//}
