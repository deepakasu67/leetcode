#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void generateAllThePossibilitiesWithMRA(string &s, int minimumRemovalAllowed, unordered_set<string>& ans, unordered_map<string , int>& dp)
    {
        if(minimumRemovalAllowed == 0)
        {
            bool validString = !minRemoveToMakeValid(s);
            if(validString)
            {
                if(ans.find(s)==ans.end())
                {
                    ans.insert(s);
                }
            }
            return;
        }
        if (dp.find(s) != dp.end())
            return;
        for(int i =0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                string leftSubstring = s.substr(0, i);
                string rightSubstring = s.substr(i + 1);
                string removalOfithChar = leftSubstring + rightSubstring;
                generateAllThePossibilitiesWithMRA(removalOfithChar, minimumRemovalAllowed - 1, ans,dp);
                dp.insert({ leftSubstring + rightSubstring , minimumRemovalAllowed });
            }
        }
    }
    int minRemoveToMakeValid(string &s)
    {
        int open = 0;
        int close = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                open++;
            }
            if (s[i] == ')')
            {
                //if we haven't seen '(' then continue;
                if (open == 0)
                {
                    close++;
                    continue;
                }
                open--;
            }
        }
        return open + close; //return imbalance open and imbalance close
    }

    vector<string> removeInvalidParentheses(string s)
    {
        int minmulaRemoval = minRemoveToMakeValid(s);
        unordered_set<string> ans;
        unordered_map<string, int> dp;
        if (minmulaRemoval == 0)
            return { s };
        generateAllThePossibilitiesWithMRA(s, minmulaRemoval, ans,dp);
        if (ans.empty())
            return{""};
        return vector<string>(ans.begin(), ans.end());
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.removeInvalidParentheses("((()((s((((()");
//}