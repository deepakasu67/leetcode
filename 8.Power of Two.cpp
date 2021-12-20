#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        if (n < 0)
            return false;
        while (n != 0)
        {
            if (n & 1)
            {
                count++;
            }
            n = n >> 1;
        }
        if (count == 1)
        {
            return true;
        }
        return false;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.isPowerOfTwo(16);
//}
