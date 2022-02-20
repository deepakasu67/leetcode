//
// Created by Deepak Sahu on 2/18/22.
//
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length())
            return "0";
        stack<char> incDig;
        int i =0;
        for(i =0;i < num.length(); i++)
        {
            while(k > 0 && !incDig.empty() && num[i] < incDig.top())
            {
                incDig.pop();
                k--;
            }
            incDig.push(num[i]);
        }
        while(k > 0)
        {
            incDig.pop();
            k--;
        }
        string res;
        while(!incDig.empty())
        {
            res.push_back(incDig.top());
            incDig.pop();
        }

        std::reverse(res.begin(), res.end());
        int idx = find_if(res.begin(), res.end(),[&](const auto &x)
        {
           return x != '0';
        }) - res.begin();
        res = res.substr(idx);
        return res;
    }
};

//int main()
//{
//    string num = "10200";
//    int k=1;
//    cout<<Solution().removeKdigits(num, k);
//}
