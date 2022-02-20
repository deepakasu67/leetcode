//
// Created by Deepak Sahu on 1/29/22.
//
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int hascode(string s, int p, int mod)
    {
        int hashCode = 0;
        for(int i = 0 ; i < s.length(); i++)
        {
          hashCode +=(((s[i] -'a' + 1) *(int)pow(p,i) )% mod);
        }
        return hashCode%mod;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        for(int i =0;i < s.length() - k; i++)
        {
            string str = s.substr(i,k);
            int hashCode = hascode(str,power,modulo);
            if(hashCode == hashValue)
                return str;
        }
        return "";
    }
};

//int main(void)
//{
//    string s = "leetcode";
//    int power = 7, modulo = 20, k = 2, hashValue = 0;
//    cout<<Solution().subStrHash(s,power,modulo,k,hashValue);
//}
