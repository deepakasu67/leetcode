#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int carry = 0;
        string result;
        int i, j;
        for(i = num1.length() - 1, j = num2.length()-1;i >=0 || j >=0 || carry;)
        {
            int first = 0, second = 0;
            if(i >= 0)
            {
                first = ((int)num1[i] - (int)'0');
                i--;
            }
            if(j >= 0)
            {
                second = ((int)num2[j] - (int)'0');
                j--;
            }
            int sum = first + second + carry;
            carry = sum / 10;
            result += to_string(sum % 10);
        }

        return string(result.rbegin(),result.rend());
    }
};

//int main(void)
//{
//    string num1 = "99";
//    string num2 = "99";
//    Solution obj;
//    cout<<obj.addStrings(num1, num2);
//}