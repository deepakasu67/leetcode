#include<iostream>
using namespace std;
class Solution {
public:
    //each power of 4 has either 4 or 6 one's digit. And power(4) is a subset of power(2) and we can solve power(2) as  (n & n-1) == 0 and check whether it has units digit 4 and 6
    bool isPowerOfFour(int num1) {
        if (num1 == 1)
            return true;
        long long int num = num1;
        if ((num & num - 1) == 0 && (num % 10 == 4 || num % 10 == 6))
            return true;
        return false;
    }
};