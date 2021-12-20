#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct comparator
{
    int  operator()(const vector<int>& a, const vector<int>& b) const
    {
        return a[1] > b[1];
    }
};


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b)
            {
                return a[0] < b[0];
            });

        priority_queue < vector<int>, vector<vector<int>>, comparator> minHeap;

        minHeap.push(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            vector<int>& curr = intervals[i];
            vector<int> prev = minHeap.top();
            minHeap.pop();
            if(prev[1] > curr[0])
            {
                minHeap.push(prev);
                minHeap.push(curr);
            }
            else
            {
                prev[1] = curr[1];
                minHeap.push(prev);
            }
        }
        return minHeap.size();
    }
};

//int main(void)
//{
//    
//    unsigned int a = -1; //4294967295
//    vector<vector<int> > intervals = { {2, 11},{6, 16},{11, 16} };
//    Solution obj;
//    obj.minMeetingRooms(intervals);
//}