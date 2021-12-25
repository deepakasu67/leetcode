#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        vector<char> result;
        int len = s.length();
        int openingBracesCount = 0;
        int closingBracesCount = 0;
        string output;
        for(int i = 0 ; i < len; i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                openingBracesCount++;
            }
            else if (s[i] == ')')
            {
                st.push(s[i]);
                closingBracesCount++;
            }

            if (closingBracesCount == openingBracesCount - 1)
            {
                while (openingBracesCount - 1 || closingBracesCount)
                {
                    result.push_back(st.top());
                    if(st.top() == '(')
                        openingBracesCount--;
                    else if(st.top() == ')')
                        closingBracesCount--;
                    st.pop();
                }
            }
            if (closingBracesCount == openingBracesCount)
            {
                while (!st.empty())
                    st.pop();
                closingBracesCount = openingBracesCount = 0;
            }
            if (result.size() >= 2)
            {
                for (int i = result.size() - 1; i >= 0; i--)
                {
                    output += result[i];
                }
                result.clear();
            }
        }
        return output;
    }
};
//
//int main(void)
//{
//    Solution obj;
//    obj.removeOuterParentheses("(()())(())(()(()))");
//}