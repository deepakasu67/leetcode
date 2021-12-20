#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int i = 0;
        for (i = 0; num > 0; i++)
        {
            if (num & 1)
            {
                num--;
            }
            else
            {
                num = num / 2;
            }
        }
        return i;
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.numberOfSteps(14);
//}