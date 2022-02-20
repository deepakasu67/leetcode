//
// Created by Deepak Sahu on 2/5/22.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long smallestNumber(long long num)
    {
        if(num == 0)
            return 0;
        bool isNegative = num < 0 ? true : false;
        string strNum = to_string(num);
        vector<int> digitFreq(10,0);
        if(strNum[0] == '-')
            strNum.erase(strNum.begin());
        for(int i =0; i < strNum.length(); i++)
        {
            digitFreq[strNum[i] -'0']++;
        }
        string result;
        if(isNegative)
        {
            for(int i = 9;i>=0;i--)
            {
                char ch  = i + '0';
                string str(digitFreq[i],ch);
                result = result + (str);
            }
        }
        else
        {
            for(int i = 0;i <= 9;i++)
            {
                char ch  =  i + '0';
                string str(digitFreq[i],ch);
                result = result + (str);
            }
            string temp = result;
            int i =0;
            for( i = 0 ;i < temp.size(); i++)
            {
                if(temp[i] != '0')
                {
                    break;
                }
            }
            string first = temp.substr(0,i);
            string second = temp.substr(i + 1);
            result = result[i] + first+ second;
        }
        return isNegative ? -1 * atoll(result.c_str()) :  atoll(result.c_str());
    }
};

//int main(void)
//{
//    Solution().smallestNumber(-00000);
//}
