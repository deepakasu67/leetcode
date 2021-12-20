#include<iostream>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) 
    {
        if (n == 0)
            return 0;
        int noOFSteps = 1;
        while (n > 0)
        {
            noOFSteps++;
            n = n - noOFSteps;            
        }
        return noOFSteps - 1;
    }
};
//int main(void)
//{
//    Solution obj;
//    cout << obj.arrangeCoins(1) << endl;
//    cout << obj.arrangeCoins(2) << endl;
//    cout << obj.arrangeCoins(5) << endl;
//}