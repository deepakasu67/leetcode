#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) 
    {
        string word;
        for (int i = 0; i < s.length(); i++)
        {
            if (word.empty() && s[i] == ' ')
            {
                continue;
            }
            if (s[i] != ' ')
            {
                string temp;
                for (; i < s.length(); i++)
                {
                    if (s[i] != ' ')
                        temp += s[i];
                    else
                        break;
                }
                word =  temp + ' ' + word ;
            }
            else
                continue;
        }
        if (!word.empty())
        {
            word.erase(word.end() - 1);
        }
        return word;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.reverseWords(" ");
//}