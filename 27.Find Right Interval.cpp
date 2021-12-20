#include<iostream>
#include<algorithm>
#include<map>
#include <set>
#include<vector>
using namespace std;
class Solution {
public:
    int upper_bound_util(vector< pair<pair<int, int>, int>>& rightIntervals, int low, int high, int target)
    {
        if (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target == rightIntervals[mid].first.first)
                return mid;
            else if (target > rightIntervals[mid].first.first)
            {
                return upper_bound_util(rightIntervals, mid + 1, high, target);
            }
            else
            {
                return upper_bound_util(rightIntervals, low, mid - 1, target);
            }
        }
        return low;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals)
    {
        vector<int> result(intervals.size());
        vector< pair<pair<int, int>, int>> rightIntervals;
        for (int i = 0; i < intervals.size(); i++)
        {
            rightIntervals.push_back(make_pair(make_pair(intervals[i][0], intervals[i][1]), i));
        }
        sort(rightIntervals.begin(), rightIntervals.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            int idx = upper_bound_util(rightIntervals, 0, intervals.size() - 1, intervals[i][1]);
            if (idx == intervals.size())
            {
                result[i] = -1;
            }
            else
                result[i] = rightIntervals[idx].second;
        }
        return result;
    }
};
//int main(void)
//{
//    vector<vector<int>> intervals = { {1, 12},{2, 9},{3, 10},{13, 14},{15, 16},{16, 17} };
//    Solution obj;
//    obj.findRightInterval(intervals);
//}
