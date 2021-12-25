#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reverseDigit = 0;
        int temp = x;
        while (temp != 0)
        {
            int lastDigit = temp % 10;
            int mulOverFlow = (long)reverseDigit * (long)10;
            cout << mulOverFlow << " " << (long)reverseDigit * (long)10;
            if (mulOverFlow / 10 != reverseDigit)
                return 0;
            reverseDigit = (reverseDigit * 10) + lastDigit;
            temp = temp / 10;
        }
        
        if (x > 0)
        {
            if (reverseDigit <= INT_MAX  && reverseDigit > 0)
                return reverseDigit;
        }
        if (x < 0)
        {
            if (reverseDigit <= INT_MAX && reverseDigit < 0)
                return reverseDigit;
        }

        return 0;

    }
};

/*int main(void)
{
    Solution obj;
    cout<<obj.reverse(-2147483647);
}*/                  