//
// Created by Deepak Sahu on 1/11/22.
//
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s)
    {
        unordered_set<int> prefixCount;
        int accumulator = 0;
        int substring=0;
        prefixCount.insert(accumulator);
        for(int i =0; i < s.length(); i++)
        {
            s[i] == '0' ? accumulator--:accumulator++;

            if(prefixCount.count(accumulator))
            {
                substring++;
            }
            prefixCount.insert(accumulator);
        }
        return substring;
    }
};

//int main(void)
//{
//    cout<<Solution().countBinarySubstrings("00110011");
//}
