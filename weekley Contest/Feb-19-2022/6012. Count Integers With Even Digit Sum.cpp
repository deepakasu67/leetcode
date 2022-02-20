//
// Created by Deepak Sahu on 2/19/22.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
    int countEven(int num) {
        int count = 0;
        while(num > 0)
        {
            if(getSum(num)%2 == 0)
                count++;
            num--;
        }
        return count;
    }
};

//int main(void)
//{
//    cout<<Solution().countEven(30);
//}
