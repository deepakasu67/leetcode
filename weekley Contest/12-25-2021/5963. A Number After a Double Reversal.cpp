//
// Created by Deepak Sahu on 12/25/21.
//
#include<iostream>
using namespace  std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num != 0 && num%10 == 0 )
        {
            return false;
        }
        return true;
    }
};

