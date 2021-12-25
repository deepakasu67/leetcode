#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() <= 1)
            return false;
        int i = 0;
        for (i=1; i < s.size();i++)
        {
            if (s[0] == s[i])
                break;
        }
        int sizeOfSubstr = i;
        string substring = s.substr(0, sizeOfSubstr);
        for(int j = sizeOfSubstr; j < s.size() ; j+=sizeOfSubstr)
        {
            string chunk = s.substr(j, sizeOfSubstr);
            if (chunk.size() != sizeOfSubstr || chunk != substring)
                return false;
        }
        return true;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.repeatedSubstringPattern("abaababaab");
//}