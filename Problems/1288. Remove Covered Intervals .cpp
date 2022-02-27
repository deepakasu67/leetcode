//
// Created by Deepak Sahu on 2/24/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        std::sort(intervals.begin(), intervals.end(),[&](const auto &interval1, const auto &interval2)
        {
            if(interval1[0] < interval2[0])
                return true;
            else if(interval1[0] == interval2[0])
            {
                return interval1[1] > interval2[1];
            }
            return false;
        });

        pair<int, int> currentInterval = {intervals[0][0],intervals[0][1]};
        int count = 0;
        for(int i =1; i < intervals.size(); i++ )
        {
            if(currentInterval.first <= intervals[i][0] && currentInterval.second >= intervals[i][1] )
                count++;
            currentInterval.first = min(currentInterval.first, intervals[i][0]);
            currentInterval.second = max(currentInterval.second, intervals[i][1]);
        }
        return intervals.size() - count;
    }
};

//int main(void)
//{
//    vector<vector<int>> intervals = {{1,2},{1,4},{3,4}};
//    cout<<Solution().removeCoveredIntervals(intervals);
//}
