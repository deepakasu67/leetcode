//
// Created by Deepak Sahu on 2/26/22.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count =0;
        for(string &word: words)
        {
            auto idx = word.find(pref);
            if( idx != string::npos && idx == 0)
                count++;
        }
        return count;
    }
};

//int main(void)
//{
//
//}
