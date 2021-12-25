#include<iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int temp = num;
        int referenceNum = 1;
        while (temp != 0)
        {
            int bitFound = num & referenceNum;
            result |= (bitFound ? 0 : referenceNum);
            referenceNum= referenceNum << 1;
            temp = temp >> 1;
        }
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.findComplement(10);
//}