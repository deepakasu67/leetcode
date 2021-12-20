#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if (x < 0)
            return false;

        int orig = x;
        int reverseDigit = 0;

        while (orig)
        {
            int unitDig = orig % 10;
            reverseDigit = reverseDigit * 10 + unitDig;
            orig = orig / 10;
        }
        return reverseDigit == x;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout << obj.isPalindrome(65);
//}