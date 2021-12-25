#include<iostream>
using namespace std;
class Solution {
public:
    int kthFactor(int n, int k)
    {
        int factor = 0;
        for(int i = 1; i <= n; i++)
        {
             factor = n % i;
            if(factor == 0)
            {
                k--;
            }
            if (k == 0)
                return i;
        }
        return -1;
    }
};
//int main(void)
//{
//    Solution obj;
//    cout<<obj.kthFactor(12, 3);
//}