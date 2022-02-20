//
// Created by Deepak Sahu on 1/2/22.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int differenceBetween(string timePoint0, string timePoint1)
    {
        int firstHr = atoi(timePoint0.substr(0,2).c_str());
        int firstMin = atoi(timePoint0.substr(3,2).c_str());
        int secondHr = atoi(timePoint1.substr(0,2).c_str());
        int secondMin = atoi(timePoint1.substr(3,2).c_str());
        int total = ((secondHr - firstHr)*60 + (secondMin-firstMin));
        return min(1440- total, total);
    }
    int findMinDifference(vector<string>& timePoints)
    {
        std::sort(timePoints.begin(), timePoints.end());

        int minDiff = INT_MAX;

        for(int i =1 ; i < timePoints.size() - 1; i++)
        {
            minDiff = min(minDiff, differenceBetween(timePoints[i],timePoints[i-1]));
        }
        return minDiff;
    }
};

//int main(void)
//{
//    vector<string> time = {"23:59","00:00"};
//    cout<<Solution().findMinDifference(time);
//}
