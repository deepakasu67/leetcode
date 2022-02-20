//
// Created by Deepak Sahu on 2/7/22.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    int numDecodingsUtils(string &s, int idx, unordered_set<string> &dp,  string IdxToDist)
//    {
//        if(s[idx] == '0')
//            return 0;
//        if(idx >= s.length())
//            return 1;
//
//        string key = to_string(idx) + '|' + '1';
//        int count = 1 + numDecodingsUtils(s, idx + 1,dp, key);
//        if(idx + 1 > s.length())
//            return count;
//        string str = s.substr(idx, 2);
//        int num = atoi(str.c_str());
//        if(num > 26)
//            return count;
//        key = to_string(idx) + '|' + '2' ;
//        count = 1 + numDecodingsUtils(s, idx + 2, dp, key);
//        return count;
//    }
//    int numDecodings(string s) {
//        unordered_set<string> dp;
//        return numDecodingsUtils(s,0, dp,"");
//    }
//};

class Solution {
public:
    int numDecodingsUtils(string &s, int idx, unordered_set<string> &dp, string idxToDist)
    {
        if(s[idx] == '0')
            return 0;
        if(idx >= s.length())
            return 1;

        if(dp.count(idxToDist))
            return 1;

        int count = 0;
        string key = to_string(idx) + "|" + '1';

        count += numDecodingsUtils(s, idx +1, dp, key);
        dp.insert(key);
        string str = s.substr(idx, 2);
        int num = atoi(str.c_str());

        if(idx + 1 >= s.length() || num > 26 )
            return count;
        key = to_string(idx) + "|" + '2';

        count += numDecodingsUtils(s, idx + 2, dp, key);
        dp.insert(key);
        return count;
    }
    int numDecodings(string s) {
        unordered_set<string> dp;
        return numDecodingsUtils(s,0, dp,"");
    }
};


//int main(void)
//{
//    string s ="12";
//    cout<<Solution().numDecodings(s);
//}
