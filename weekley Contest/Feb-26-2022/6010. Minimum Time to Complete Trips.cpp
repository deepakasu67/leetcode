//
// Created by Deepak Sahu on 2/26/22.
//
#include <iostream>
#include <vector>
using namespace std;
typedef long long int lld;
class Solution {
public:
    lld counttotalTrips(vector<int> &time, lld givenTime)
    {
        lld trips = 0;
        for(lld a : time)
        {
            trips += (givenTime / a);
        }
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips)
    {
        lld low = 0 , high = 1e14;
        while(low < high)
        {
           lld mid = (high + low)/2;
            if(counttotalTrips(time, mid) >= totalTrips)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

//int main(void)
//{
//    vector<int> time = {2};
//    int totalTrips = 1;
//    cout<<Solution().minimumTime(time, totalTrips);
//}
