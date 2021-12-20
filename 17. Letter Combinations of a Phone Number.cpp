#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void generate(vector<string> &result, string tmpResult, vector<string> &keypadString, string digits, int idx)
    {
        if (idx == digits.length())
        {
            result.push_back(tmpResult);
            return;
        }
        for (int i = 0; i < keypadString[digits[idx] - '2'].length(); i++)
        {
            generate(result, tmpResult + keypadString[digits[idx] - '2'][i], keypadString, digits, idx + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> keypadString = { "abc" , "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        if (digits.empty())
            return result;
        generate(result, "", keypadString,digits, 0);
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.letterCombinations("23");
//}