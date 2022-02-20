//
// Created by Deepak Sahu on 1/3/22.
//
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    long long sumOfSquaresOfEachDig(string s)
    {
        long long sum = 0;
        for(char ch: s)
        {
            int num = ch - '0';
            sum+= num*num;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<string> numForm;
        string str = to_string(n);
        while(str != "1")
        {
            str = to_string(sumOfSquaresOfEachDig(str));
            if(numForm.count(str))
                return false;
            numForm.insert(str);
        }
        return true;
    }
};

//int main(void)
//{
//    cout<<boolalpha;
//    cout<<Solution().isHappy(19);
//}
