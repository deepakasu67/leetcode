#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& i1, vector<int>& i2)
            {
                return i1[0] < i2[0];
            });
        int pick = 0;
        int result = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[pick][1] > intervals[i][0]) //overlap
            {
                result++;
                //if current included end time is less than last picked end time
                //then pick which has less end time so that there would be less chances of overlap in future
                if (intervals[pick][1] > intervals[i][1]) pick = i;
            }
            else
                pick = i;
        }
        return result;
    }
};
//int main(void)
//{
//    vector<vector<int>> intervals = {{1,100},{11,22},{1,11},{2,12}};
//    Solution obj;
//    obj.eraseOverlapIntervals(intervals);
//}