#include<iostream>
#include <stack>
#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
    string decodeAtIndex(string S, int K)
    {
        vector<unsigned long> lengthOfchars;
        lengthOfchars.push_back(1);
        for(unsigned long i = 1; i < S.length(); i++)
        {
            if(isdigit(S[i]))
            {
                unsigned long digit = S[i] - '0';
                lengthOfchars.push_back(lengthOfchars.back() * digit);
            }
            else
            {
                lengthOfchars.push_back(lengthOfchars.back() + 1);
            }
        }
        for(int i = lengthOfchars.size() - 1; i >= 0;--i)
        {
            if(lengthOfchars[i] < K)
            {
                if(K % lengthOfchars[i] != 0)
                {
                    K = K % lengthOfchars[i];
                }
                else
                {
                    K = lengthOfchars[i];
                }
            }
            if(lengthOfchars[i] == K && !isdigit(S[i]))
            {
                return S.substr(i, 1);
            }
        }
        return S.substr(0, 1);
    }
};

//int main(void)
//{
//    string s = "leet2code3";
//    int k = 20;
//    Solution obj;
//    cout<<obj.decodeAtIndex(s, k);
//}