#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    string say(string digits)
    {
        string say;
        int count = 1;
        for (int i = 0; i < digits.length(); i++)
        {
            if (i == digits.length() || digits[i] != digits[i + 1])
            {
                say += (to_string(count) + digits[i]);
                count = 1;
                continue;
            }
            count++;
        }
        return say;
    }
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 2; i <= n; i++)
        {
            prev = say(prev);
        }
        return prev;
    }
};
//
//int main(void)
//{
//    Solution obj;
//    obj.countAndSay(5);
//}