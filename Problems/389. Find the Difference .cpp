//
// Created by Deepak Sahu on 2/6/22.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sCharMap(26,0), tCharMap(26,0);

        for(int i =0; i < s.length(); i++)
        {
            sCharMap[s[i] - 'a']++;
        }
        for(int i =0; i < t.length(); i++)
        {
            sCharMap[t[i] - 'a']++;
        }
        for(int i =0; i < 26; i++)
        {
            if(sCharMap[i] != tCharMap[i])
            {
                return 'a' + i;
            }
        }
    }
};

//int main(void)
//{
//
//}
