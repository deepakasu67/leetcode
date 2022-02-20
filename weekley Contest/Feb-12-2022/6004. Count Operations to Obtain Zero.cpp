//
// Created by Deepak Sahu on 2/12/22.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2)
    {
        if(num1 == 0 || num2 == 0)
            return 0;

        if(num1 >= num2)
        {
            return 1 + countOperations(num1 - num2, num2);
        }
        else
        {
            return  1 + countOperations(num1,num2-num1);
        }
    }
};

//int main(void)
//{
//    cout<<Solution().countOperations(2,3);
//}