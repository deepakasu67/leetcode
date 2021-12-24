#include<iostream>
#include<string>
using namespace std;
class Solution {
    string result;
public:
    char convertToTitleUtil(int n)
    {
        if (n <= 26)
            return 'A' + n;
        if (n > 26)
            result += 'Z';
        result += convertToTitleUtil(n / 26);
        return ' ';
    }
    string convertToTitle(int n)
    {
        convertToTitleUtil(n);
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.convertToTitle(52);
//}
