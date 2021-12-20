#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

    class Solution {
    public:
        int balancedString(string s)
        {
            unordered_map<char, int> charFreq = { {'Q',0},{'W',0},{'R',0},{'E',0}};

            int flipToBalance = 0;
            for (int i = 0; i < s.length(); i++)
            {
                charFreq[s[i]]++;

                if ((i + 1) % 4 == 0)
                {
                    int times = (i + 1) / 4;
                    for (auto& it : charFreq)
                    {
                        if (it.second > times)
                        {
                            int diff = (it.second - times);
                            flipToBalance += diff;
                            it.second -= diff;
                            for (auto& itr : charFreq)
                            {
                                if (itr.second < times)
                                {
                                    int required = times - itr.second;
                                    if (required >= diff)
                                    {
                                        itr.second = diff;
                                        diff = 0;
                                        break;
                                    }
                                    else
                                    {
                                        itr.second = required;
                                        diff = required - diff;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return flipToBalance;
        }
    };

//int main(void)
//{
//    string str = "WWQQRRRRQRQQ";
//    Solution obj;
//    obj.balancedString(str);
//}