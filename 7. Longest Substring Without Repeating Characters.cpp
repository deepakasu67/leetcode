#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        int lead = 0;
        int trail = 0;
        int longestSubStrWithoutRepeats = 1;
        unordered_map<int,int> charCount;
        for(lead = 0; lead < s.length(); lead++)
        {
            if(charCount[s[lead]] != 0)
            {
                while(trail < lead)
                {
                    charCount[s[trail]]--;
                    if(s[trail++] == s[lead])
                    {
                        break;
                    }
                }
            }
            longestSubStrWithoutRepeats = max(longestSubStrWithoutRepeats, (lead - trail) + 1);
            charCount[s[lead]]++;
        }
        return longestSubStrWithoutRepeats;
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.lengthOfLongestSubstring("abcabcbb");
//}