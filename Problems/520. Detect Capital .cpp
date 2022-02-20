//
// Created by Deepak Sahu on 1/23/22.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word)
    {
        int capitol = 0;
        int capitolIdx = -1;
        int small = 0;
        int n = word.length();
        for(int i =0;i < word.length(); i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
            {
                if(capitolIdx == -1)
                    capitolIdx = i;
                capitol++;
            }
            else
            {
                small++;
            }
        }

        if(small == n)
            return true;
        if(small == n - 1 && capitolIdx == 0 && capitol == 1)
            return true;
        if(capitol == n)
            return true;

        return false;
    }
};

//int main(void)
//{
//    cout<<boolalpha;
//    cout<<Solution().detectCapitalUse("USA")<<endl;
//    cout<<Solution().detectCapitalUse("FlaG")<<endl;
//    cout<<Solution().detectCapitalUse("leetcode")<<endl;
//    cout<<Solution().detectCapitalUse("Google")<<endl;
//}
