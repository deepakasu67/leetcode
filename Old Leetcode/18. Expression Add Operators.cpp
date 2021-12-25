#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void addOperators(string& num, long prevVal, int idx, string prevExp, int target, vector<string>& ans, long prevNum)
    {
        if (idx >= num.length())
        {
            if (prevVal == target)
            {
                ans.push_back(prevExp);
            }
            return;
        }
        string firstNum;
        long numb = 0;
        for (int i = idx; i < num.length(); i++)
        {
            if (i > idx && num[idx] == '0')
                break;
            firstNum += num[i];
            numb = atol(firstNum.c_str());
            if (prevExp.empty())
            {
                addOperators(num, numb, i + 1, firstNum, target, ans, numb);
            }
            else
            {
                addOperators(num, prevVal + numb, i + 1, (prevExp + "+" + (firstNum)), target, ans, numb);
                addOperators(num, prevVal - numb, i + 1, (prevExp + "-" + (firstNum)), target, ans, -numb);
                addOperators(num, prevVal - prevNum + prevNum * numb, i + 1, (prevExp + "*" + (firstNum)), target, ans, prevNum * numb);
            }
        }
    }
    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;

        addOperators(num, 0, 0, "", target, ans, 0);

        return ans;
    }
};
//int main(void)
//{
//    string nums = "1212";
//    int target = 0;
//
//    Solution obj;
//    obj.addOperators(nums, target);
//}