#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string afterConcatWord1;
        string afterConcatWord2;
        for (string& word : word1)
        {
            afterConcatWord1 += word;
        }
        for (string& word : word2)
        {
            afterConcatWord2 += word;
        }
        if (afterConcatWord1 == afterConcatWord2)
            return true;
        return false;
    }
};