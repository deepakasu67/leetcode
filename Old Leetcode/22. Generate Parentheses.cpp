#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    int n;
public:
    void generateParenthesis(vector<string> &ans, int open,int close, string validParTillNow)
    {
        if (open > n || close > n)
            return;
        if (open == n && n == close)
        {
            ans.push_back(validParTillNow);
            return;
        }
        
        generateParenthesis(ans, open + 1, close, validParTillNow + '(');

        if (close < open)
            generateParenthesis(ans, open, close + 1, validParTillNow + ')');

    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        vector<string> ans;
        string validParTillNow = "(";
        generateParenthesis(ans, 1, 0, validParTillNow);

        return ans;
    }
};

//int main(void)
//{
//    Solution().generateParenthesis(3);
//}