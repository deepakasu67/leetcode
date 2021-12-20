#include<iostream>
#include<string>
using namespace std;

class Solution {
    string afterTenths[5] = { "","Thousand", "Million", "Billion"};

    string lessThanTwenty[20] = { "", "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
     "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    string tens[10] = { "","","Twenty","Thirty","forty","fifty","sixty","seventy", "Eighty","Ninety" };

public:
    void helper(string &str, int num)
    {
        if (num == 0)
            return;
        if(num < 20)
        {
            str = str + " " + lessThanTwenty[num];
            return;
        }
        else if(num < 100)
        {
            str = str + " " + tens[num / 10];
            helper(str, num % 10);
        }
        else
        {
            str = lessThanTwenty[num / 100] + " Hundered " + str;
            helper(str, num % 100);
        }
    }
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        string result;
        int indexForAfterTenths = 0;
        while(num>0)
        {
            if(num%1000 > 0)
            {
                string tmp;
                helper(tmp, num % 1000);
                tmp = tmp + " " + afterTenths[indexForAfterTenths];
                result = tmp + " " + result;
            }
            num = num / 1000;
            indexForAfterTenths++;
        }
        string trimResult;
        int start = 0;
        int end = result.size() - 1;

        while (result[start] == ' ' || result[end] == ' ')
        {
            if (result[start] == ' ')
                start++;
            if (result[end] == ' ')
                end--;
        }

        return { result.begin() + start, result.begin() + end +1};
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.numberToWords(1001);
//}