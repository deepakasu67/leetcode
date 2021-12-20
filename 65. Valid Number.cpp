#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        // first trim the sentinal whitespaces
        while (s[start] == ' ' || s[end] == ' ')
        {
            if (s[start] == ' ')
                start++;
            if (s[end] == ' ')
                end--;
        }
        if (s[start] == '-' || s[start] == '+') start++;
        bool numSeen = false;
        bool dotSeen = false;
        bool exponentSeen = false;
        for (int i = start; i <= end; i++)
        {
            // if it is number
            if (isdigit(s[i]))
            {
                numSeen = true;
            }
            // if it is e
            else if (s[i] == 'e' || s[i] == 'E')
            {
                // if we have not seen a number before 
               // or we have seen the e before then we return false
                if (numSeen == false || exponentSeen == true)
                    return false;
                exponentSeen = true;
                // when we see the e we want to see atleast a number after e
                numSeen = false;
            }
            else if (s[i] == '.')
            {
                // decimal is not allowed when it is alreay seen 
               // or we have seen e before
                if (dotSeen || exponentSeen)
                    return false;
                dotSeen = true;
            }
            // + or -
            else if (s[i] == '-' || s[i] == '+')
            {
                // if pervious characer is not e then we return false
               // +- is allowed only after e
                if (s[i - 1] == 'e' || s[i - 1] == 'E')
                    continue;
                else
                    return false;
            }
            else
                return false;
        }
        // if we haven't seen number till last then this string is wrong
        return numSeen;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.isNumber("005047e+6");
//}
