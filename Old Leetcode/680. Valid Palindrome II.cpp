#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s)
    {
        int j = s.length() - 1;
        for (int i = 0; i < j; i++)
        {
            if (s[i] != s[j])
                return false;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int count = 0;
        int j = s.length() - 1;

        for (int i = 0; i < j; i++)
        {
            if (s[i] != s[j])
            {
                string temp = s.substr(0, i);
                temp += s.substr(i + 1, s.length());
                if (isPalindrome(temp))
                {
                    return true;
                }
                string temp1 = s.substr(0, j);
                if(j < s.length() - 1)
                    temp1 += s.substr(j + 1, s.length());


                if (isPalindrome(temp1))
                {
                    return true;
                }
                return false;
            }
            j--;
        }
        return true;
    }
};
//int main(void)
//{
//    Solution obj;
//    //string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
//    string s = "eccer";
//    cout<<obj.validPalindrome(s);
//}