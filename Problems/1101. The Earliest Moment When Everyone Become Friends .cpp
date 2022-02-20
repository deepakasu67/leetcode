//
// Created by Deepak Sahu on 2/15/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> parent;
public:
    int find(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }
        return find(parent[x]);
    }

    bool Union(int x, int y)
    {
        int parOfX = find(x);
        int parOfY = find(y);
        if (parOfX != parOfY)
        {
            parent[parOfX] = parOfY;
            return true;
        }
        return false;
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        parent.resize(n);
        std::sort(logs.begin(), logs.end());
        for(int i =0; i < parent.size(); i++)
            parent[i] = i;

        int lastTimeStamp = logs[0][0];
        for(auto &log : logs)
        {
            int timeStmp = log[0];
            int x = log[1];
            int y = log[2];
            if(Union(x,y))
            {
                lastTimeStamp = timeStmp;
            }
        }
        return lastTimeStamp;
    }
};

//int main(void)
//{
//    vector<vector<int>> logs = {
//            {20190101,0,1},
//            {20190104,3,4},
//            {20190107,2,3},
//            {20190211,1,5},
//            {20190224,2,4},
//            {20190301,0,3},
//            {20190312,1,2},
//            {20190322,4,5}
//    };
//    int n = 6;
//    cout<<Solution().earliestAcq(logs,6);
//}
