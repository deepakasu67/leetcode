//
// Created by Deepak Sahu on 2/15/22.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k)
    {
        vector<int> charFreq(26,0);
        int countOfSubstring = 0;
        int j = 0;
        for(int i = 0;i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            charFreq[idx]++;
            if(charFreq[idx] == 1 && i - j + 1== k)
            {
                countOfSubstring++;
            }
            else if(charFreq[idx] > 1)
            {
                while(charFreq[idx] != 1 && j < i)
                {
                    charFreq[s[j] - 'a']--;
                    j++;
                }
                if(i - j + 1 == k)
                    countOfSubstring++;
            }
            else if(i - j+ 1 > k)
            {
                while(i - j + 1 != k && j < i)
                {
                    charFreq[s[j]-'a']--;
                    j++;
                }
                countOfSubstring++;
            }

        }
        return countOfSubstring;

    }
};

//int main(void)
//{
//    string str = "havefunonleetcode";
//    int k = 5;
//    cout<<Solution().numKLenSubstrNoRepeats(str,k);
//}
