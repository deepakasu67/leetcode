#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int maxPower(string s)
    {
        int powerSoFar = 1;
        int maxpower = 0;
        for(int i = 1 ;i < s.length(); i++)
        {
            if(s[i] != ' ' && s[i] == s[i-1])
            {
                powerSoFar++;
            }
            else
            {
                powerSoFar = 1;
            }
            maxpower = max(powerSoFar, maxpower);
        }
        return maxpower;
    }
};
//int main(void)
//{
//    Solution obj;
//    cout<<obj.maxPower("triplepillooooow");
//}