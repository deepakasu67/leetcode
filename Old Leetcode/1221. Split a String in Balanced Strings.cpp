#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int len = s.length();
        stack<char> st;
        bool R = false, L = false;
        s[0] == 'R' ? R = true : L = true;
        int output = 0;
        for (int i = 0; i < len; i++)
        {
            if (R)
            {
                if (s[i] == 'L')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
                if (st.empty())
                {
                    output++;
                    R = false;
                    L = false;
                    if (i + 1 < len)
                        s[i + 1] == 'R' ? R = true : L = true;
                }
            }
            else if (L)
            {
                if (s[i] == 'R')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
                if (st.empty())
                {
                    output++;
                    R = false;
                    L = false;
                    if (i + 1 < len)
                        s[i + 1] == 'R' ? R = true : L = true;
                }
            }
        }
        return output;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.balancedStringSplit("RLRRRLLRLL");
//                                   //RLLLLRRRLR      
//}