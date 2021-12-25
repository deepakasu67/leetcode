#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<char> vowels = { 'a','e','i','o','u' };
    void countVowelStrings(int n, int &ans, string &generatedString)
    {
        if(n == 0)
        {
            ans++;
            return;
        }
        for(int i =0 ; i < vowels.size();i++)
        {
            if( generatedString.empty() || generatedString.back() <= vowels[i])
            {
                generatedString.push_back(vowels[i]);
                countVowelStrings(n - 1, ans, generatedString);
                generatedString.pop_back();
            }
        }
    }
    int countVowelStrings(int n)
    {
        int ans = 0;
        string generatedString;
        countVowelStrings(n, ans, generatedString);
        return ans;
    }
};
//
//int main(void)
//{
//    Solution obj;
//    obj.countVowelStrings(33);
//}