//
// Created by Deepak Sahu on 1/23/22.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
    map<int,pair<int,int>> startingPoint = {
            {2,{12, 10}},
            {3,{123, 100}},
            {4,{1234, 1000}},
            {5,{12345, 10000}},
            {6,{123456, 100000}},
            {7,{1234567, 1000000}},
            {8,{12345678, 10000000}},
            {9, {123456789, 100000000}}
    };
public:
    vector<int> sequentialDigits(int low, int high)
    {
        string strNum = to_string(low);
        string strt(1, strNum[0]);

        //first find the starting point from where we e
        for(int i =1;i < strNum.length(); i++)
        {
            if(strt.back() == '9')
            {
                if(strNum.length() + 1 < 9)
                    strt = to_string(startingPoint[strNum.length() + 1].first);
                break;
            }
            strt += (strt[i-1] + 1);
        }

        int start = atoi(strt.c_str());
        int startDeno = startingPoint[strt.length()].second;
        int currIdx = strt.length();
        vector<int> result;
        while(start <= high && currIdx <= 9)
        {
            if(start >= low && start <= high)
                result.push_back(start);

            int nextNumberToPrepend = start%startDeno;
            int nextDig = start%10;
            if(nextDig == 9)
            {
                start = startingPoint[++currIdx].first;
                startDeno = startingPoint[currIdx].second;
            }
            else
            {
                start = nextNumberToPrepend*10+(nextDig+1);
            }
        }
        return result;
    }
};

//int main(void)
//{
//    Solution().sequentialDigits(99,300);
//   Solution().sequentialDigits(1000,13000);
//      Solution().sequentialDigits(900,1500);
//
//}
//int a = 10;
//class dog
//{
//public:
//    string pName;
//    dog():pName("Bob"){}
//    void bark() const
//    {
//        cout<<"My name is  "<< pName;
//        a =5;
//    }
//};
//
//int main()
//{
//    int *p = nullptr;
//    cout<<*p;
//}
