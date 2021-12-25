#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool isSubsequence = true;
        size_t found = -1;
        for (int i = 0; i < s.length(); i++)
        {
           found =  t.find(s[i], found + 1);
           if (found == string::npos)
           {
               isSubsequence = false;
               break;
           }
           isSubsequence = true;
        }
        return isSubsequence;
    }
};
//
//int main(void)
//{
//    string s = "acb", t = "ahbgdc";
//    Solution obj;
//    obj.isSubsequence(s,t);
//}