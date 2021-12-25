#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S)
    {
        if (S.empty())
            return "";
        vector<char> result(S.size());
        result[0] = S[0];
        int curResultIdx = 0;
        for(int i = 1; i < S.size(); i++)
        {
            if(curResultIdx >= 0 && result[curResultIdx] == S[i])
            {
                curResultIdx--;
            }
            else
            {
                curResultIdx++;
                result[curResultIdx] = S[i];
            }
        }
        return string(result.begin(), result.begin() + curResultIdx+1);
    }
};

//int main(void)
//{
//    string str = "abbaca";
//    Solution obj;
//    cout<<obj.removeDuplicates(str);
//}