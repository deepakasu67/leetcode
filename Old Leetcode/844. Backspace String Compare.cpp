#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;
        while(i >=0 || j >= 0)
        {
            while(i >= 0)
            {
                if(S[i] == '#')
                {
                    skipS--; i--;
                }
                else if(skipS < 0)
                {
                    skipS++; i--;
                }
                else
                {
                    break;
                }
            }
            while(j >= 0)
            {
                if(T[j] == '#')
                {
                    skipT--; j--;
                }
                else if(skipT < 0)
                {
                    skipT++; j--;
                }
                else
                {
                    break;
                }
            }

            if (i >= 0 && j >= 0 && S[i] != T[j]) //after skipping, lets check wether both are same
                return false;

            if (i >= 0 && j < 0 || j >= 0 && i < 0) // let check there is some characters in S and T is exhausted
                return false;
            i--; j--;
        }
        return true;
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.backspaceCompare("a##c", "#a#c");
//}
