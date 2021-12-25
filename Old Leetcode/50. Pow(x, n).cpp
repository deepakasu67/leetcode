#include<iostream>
using namespace std;

class Solution {
public:

    double myPowUtil(double x, long n)
    {
        if (n == 0)
            return 1;

        double result = myPow(x, n / 2);
        result *= result;
        if (n % 2 == 1)
            result = result * x;
        return result;
    }
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            if (n != INT_MIN)
                n = -n;
            else
                n = INT_MAX;
            x = 1 / x;
        }
        return myPowUtil(x, n);
    }

};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.myPow(34.00515, -3);
//}