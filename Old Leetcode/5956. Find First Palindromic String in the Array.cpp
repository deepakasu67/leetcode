#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) 
    {
        for (auto &str : words)
        {
            string st = str;
            reverse(str.begin(), str.end());
            if (st == str)
                return st;
        }
        return "";
    }
};
