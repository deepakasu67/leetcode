#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isVowel(char c)
    {
        bool isLowercaseVowel = false, isUppercaseVowel = false;;
        isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        return isLowercaseVowel || isUppercaseVowel;
    }
    string operateOnString(string S, int i, int spaceCount)
    {
        string stringTOBeApp ="";
        string numOFA(spaceCount + 1, 'a');
        if (isVowel(S[i]))
        {
            stringTOBeApp = string("ma") + numOFA;
        }
        else
        {
            stringTOBeApp = (S[i] + string("ma") + numOFA);
        }
        return stringTOBeApp;
    }
    string toGoatLatin(string S)
    {
        int spaceCount = 0;
        string stringTOBeAppended = "";
        string result;
        for(int i = 0 ; i < S.length(); i++)
        {
            if(i == 0)
            {
                stringTOBeAppended = operateOnString(S, i, spaceCount);
                if (isVowel(S[i]))
                    result += S[i];
            }
            else if(S[i] == ' ')
            {
                spaceCount++;
                if (!stringTOBeAppended.empty())
                {
                    result += stringTOBeAppended;
                    stringTOBeAppended.erase();
                }
                if(i < S.length() - 1)
                {
                    stringTOBeAppended = operateOnString(S, i + 1, spaceCount);
                    result += ' ';
                    if (isVowel(S[i+1]))
                        result += S[i + 1];
                    i++;
                }
            }
            else
            {
                result += S[i];
            }
        }
        return result+stringTOBeAppended;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.toGoatLatin("I speak Goat Latin");
//}