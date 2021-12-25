#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string decodeString(string s)
    {
        if(s.size() == 1)
        {
            if (isdigit(s[0]))
                return "";
            else
                return s;
        }
        stack<string> st;
        for(int i = 0; i < s.size(); i++)
        {
            string intermediateResult;
            if(s[i] == ']')
            {
                while (st.empty() == false && st.top() != "[")
                {
                     intermediateResult = st.top() + intermediateResult;
                     st.pop();
                }
                st.pop();
                string result;

                if(isdigit(st.top()[0]))
                {
                    int n = stoi(st.top());
                    while(n--)
                    {
                        result += intermediateResult;
                    }
                    st.pop();
                    st.push(result);
                }
            }
            else
            {
                string digit;
                if(isdigit(s[i]))
                {
                   for(; i < s.size() && isdigit(s[i]);)
                   {
                       digit += s[i];
                       i++;
                   }
                   i--;
                   st.push(digit);
                }
                else
                    st.push(string(1,s[i]));
            }
        }
        string result;
        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout << obj.decodeString("100[leetcode]");
//}