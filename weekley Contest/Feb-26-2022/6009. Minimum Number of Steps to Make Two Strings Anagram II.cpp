//
// Created by Deepak Sahu on 2/26/22.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t)
    {
        vector<int> charMapOfS(26,0);
        vector<int> charMapOfT(26,0);

        for(int i =0; i < s.length(); i++)
        {
            charMapOfS[s[i] - 'a']++;
        }

        for(int i =0; i < t.length(); i++)
        {
            charMapOfT[t[i] - 'a']++;
        }

        int count = 0;
        for(int i =0; i < 26; i++)
        {
            count += abs(charMapOfS[i] - charMapOfT[i]);
        }
        return count;
    }
};

//int main(void)
//{
//    string s = "night";
//    string t = "thing";
//    cout<<Solution().minSteps(s,t);
//}
