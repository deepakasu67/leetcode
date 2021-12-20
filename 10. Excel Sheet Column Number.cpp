#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int exp = 0;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            result += pow(26, exp++) * (s[i] - 'A' + 1);
        }
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.titleToNumber("ABC");
//}