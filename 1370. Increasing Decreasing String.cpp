#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        int charCount[26] = { 0 };
        int len = s.length();
        string result;
        for (int i = 0; i < len; i++)
        {
            charCount[s[i] - 'a']++;
        }
        for (int j = 0; j < len; )
        {
            for (int i = 0; i < 26; i++)
            {
                if (charCount[i] > 0)
                {
                    result += ((char)('a' + i));
                    charCount[i]--;
                    j++;
                }
            }
            for (int i = 25; i >= 0; i--)
            {
                if (charCount[i] > 0)
                {
                    result += ((char)('a' + i));
                    charCount[i]--;
                    j++;
                }
            }
        }
        return result;
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.sortString("aaaabbbbcccc");
//}