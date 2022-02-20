//
// Created by Deepak Sahu on 1/8/22.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords)
    {
        unordered_set<string> startWordMap;
        for(auto it = startWords.begin(); it!=startWords.end(); it++)
        {
            sort(it->begin(), it->end());
            startWordMap.insert(*it);
        }
        for(auto it = targetWords.begin(); it!=targetWords.end(); it++)
        {
            sort(it->begin(), it->end());
        }

        int count = 0;
        for(int i = 0; i < targetWords.size(); i++)
        {
            string str = targetWords[i];
            str.pop_back();
            if(startWordMap.count(str))
                count++;
        }
        return count;
    }
};

//int main(void)
//{
//    vector<string> startWord = {"ant","act","tack"};
//    vector<string> targetWords = {"tack","act","acti"};
//    Solution().wordCount(startWord,targetWords);
//}
