#include<iostream>
#include<string>
using namespace std;

class Solution {
    string beforeMultiply;
public:
    Solution() : beforeMultiply("")
    {

    }

    void addTwoNumericString(string aftermultiply, string &beforeMultiply)
    {
        int carry = 0;
        string addedNum;
        for (int i = aftermultiply.length() - 1, j = beforeMultiply.length() - 1;
            i >= 0 || j >= 0 || carry; 
            i--, j--)
        {
            int sum = (i >= 0 ? aftermultiply[i] - '0' : 0)
                         + (j >= 0 ? beforeMultiply[j] - '0' : 0)
                         + carry;
            carry = sum >= 10 ? 1 : 0;
            int value = sum % 10;
            addedNum += (char)(value + '0');
        }
        reverse(addedNum.begin(), addedNum.end());
        beforeMultiply = addedNum;
    }
    void multiplyUtil(string num1, char eachNumStr, int numberOfZero)
    {
        string  aftermultiply;
        int carry = 0;
        int eachNumInt = eachNumStr - '0';
        for (int i = num1.size() - 1; i >= 0 || carry; i--)
        {
            int mulNum = (i >= 0 ? num1[i] - '0' : 0) * eachNumInt + carry;
            int ones = mulNum % 10;
            int tens = (int)(mulNum % 100) / 10;
            carry = tens;
            aftermultiply += (char)(ones + '0');
        }
        reverse(aftermultiply.begin(), aftermultiply.end());
        aftermultiply.append(numberOfZero, '0');
        addTwoNumericString(aftermultiply, beforeMultiply);
    }
    string multiply(string num1, string num2) {
        if ((num1.length() == 1 && num1[0] == '0') || (num2.length() == 1 && num2[0] == '0'))
            return "0";
        string Bignum;
        string smallNum;
        string result;
        num1.length() >= num2.length() ? Bignum = num1 : smallNum = num2;
        num1.length() < num2.length() ? Bignum = num1 : smallNum = num2;
        int smalllength = smallNum.length() - 1;
        for (int i = smalllength; i >= 0; i--)
        {
           multiplyUtil(Bignum, smallNum[i], smalllength - i);
        }
        return beforeMultiply;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.multiply("9333","0");
//}
