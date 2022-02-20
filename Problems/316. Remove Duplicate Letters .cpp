//
// Created by Deepak Sahu on 12/29/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace  std;

class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> lastIdx(26,0);
        for(int i = 0 ; i < s.length(); i++)
        {
            lastIdx[s[i] - 'a'] = i;
        }

        vector<bool> seen(26, false);
        stack<char> st;

        for(int i = 0 ; i < s.length(); i++)
        {
            if(seen[s[i] - 'a']== true)
                continue;

            while(!st.empty() && st.top() > s[i] && lastIdx[st.top() - 'a'] > i) {
                seen[st.top()-'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[s[i]- 'a'] = true;
        }

        string t;

        while(!st.empty())
        {
            t.push_back(st.top());
            st.pop();
        }
        std::reverse(t.begin(), t.end());
        return  t;
    }
};

//int main(void)
//{
//    cout<<Solution().removeDuplicateLetters("bcabc");
//
//}
