#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int validParenthesis = 0;
        string result;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                validParenthesis++;
            }
            if(s[i] == ')')
            {
                //if we haven't seen '(' then continue;
                if (validParenthesis == 0) continue;
                validParenthesis--;
            }
            result += s[i];
        }
        string finalResult;
        for(int i = result.length()-1; i >= 0; i--)
        {
            if (result[i] == '(' && validParenthesis-- > 0) continue;
            finalResult += result[i];
        }
        return string(finalResult.rbegin(), finalResult.rend());
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.minRemoveToMakeValid("lee(t(c)o)de)(((");
//}