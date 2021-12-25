#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s)
    {
        s.erase(std::remove_if(s.begin(), s.end(),
            [](auto & c) -> bool
            {
                c = towlower(c);
                return !std::isalnum(c);
            }), s.end());

        int j = s.length() - 1;
        for(int i = 0 ; i < j;i++)
        {
            if (s[i] != s[j])
                return false;
            j--;
        }
        return true;
    }
};
//int main(void)
//{
//    Solution obj;
//    cout<<obj.isPalindrome("");
//}