#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef long long unsigned int llud;
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        if (S.length() != shifts.size())
            return "";
        if (S.empty() || shifts.empty())
            return "";
        vector<llud> noOfshiftsachChar(S.length(), 0);
        noOfshiftsachChar[S.length() - 1] = shifts[shifts.size() - 1];
        for (int i = shifts.size() - 2; i >= 0; i--)
        {
            noOfshiftsachChar[i]  = noOfshiftsachChar[i+1] + shifts[i];
        }
        for (int i = 0; i < S.length(); i++)
        {
            S[i] = (S[i] - 'a' + noOfshiftsachChar[i]) % 26 + 'a';
        }
        return S;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> a ({505870226,437526072,266740649,224336793,532917782,311122363,567754492,595798950,81520022,684110326,137742843,275267355,856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513});
//    obj.shiftingLetters("mkgfzkkuxownxvfvxasy",a );
//    char ch = 'b' + 14;
//}