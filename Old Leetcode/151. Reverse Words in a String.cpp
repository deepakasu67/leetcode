#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) 
    {
        s.append(0, ' ');
        string ans;
        string temp;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && temp.length() != 0)
            {
                ans += ' ' + temp;
                temp.clear();
            }
            else if(s[i] != ' ')
            {
                temp.insert(temp.begin(),s[i]);
            }
        }
        return string(ans.begin() + 1, ans.end());
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.reverseWords("   the sky is   blue");
//}