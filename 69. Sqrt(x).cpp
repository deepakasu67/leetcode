#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) 
    {
        int low = 0;
        int high = x;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid * mid == x)
                return mid;
            if (mid*mid < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};

//int main(void)
//{
//    cout<<Solution().mySqrt(15);
//}