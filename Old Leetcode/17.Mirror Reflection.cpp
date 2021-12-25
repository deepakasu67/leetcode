#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
        {
            return {};
        }
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b)
            {
                return a[0] < b[0];
            });
        int resultIdx = 0;
        result.push_back(intervals[0]);
        int intervalSize = intervals.size();
        for (int i = 1; i < intervalSize; i++)
        {
            if (result[resultIdx][1] < intervals[i][0])
            {
                result.push_back(intervals[i]);
                resultIdx++;
            }
            else if (result[resultIdx][1] < intervals[i][1])
            {
                result[resultIdx][1] = intervals[i][1];
            }
        }
        return result;
    }
};
//
//int main(void)
//{
//    vector<vector<int>> intervals = { {1, 3},{2, 3},{8, 10},{15, 18} };
//    Solution obj;
//    obj.merge(intervals);
//}