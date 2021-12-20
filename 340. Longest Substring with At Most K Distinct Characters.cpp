#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        unordered_map<int,int> charMap;
        int trail = 0;
        int result = 0;
        for(int lead = 0; lead < s.size(); lead++)
        {
            charMap[s[lead]]++;

            int countdistinct = 0;
            for (auto element : charMap)
            {
                if (element.second != 0)
                    countdistinct++;
            }
            if(countdistinct <= k)
            {
                result = max(result, lead - trail + 1);
            }
            else
            {
                charMap[s[trail]]--;
                trail++;
            }

        }
        return result;
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.lengthOfLongestSubstringKDistinct("a@b$5!a8alskj234jasdf*()@$&%&#FJAvjjdaurNNMa8ASDF-0321jf?>{}L:fh", 10);
//}