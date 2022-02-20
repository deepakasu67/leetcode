//
// Created by Deepak Sahu on 12/30/21.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

template<typename OutStream, typename T>
OutStream& operator<< (OutStream& out, const vector<T>& v)
{
    for (auto const& tmp : v)
        out << tmp << " ";
    out << endl;
    return out;
}


class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        std::sort(slots1.begin(), slots1.end());
        std::sort(slots2.begin(), slots2.end());

        int i1 = 0;
        int i2 = 0;
        vector<int> overLapContainer;

        while(i1 < slots1.size() && i2 < slots2.size())
        {
            int overlapStart = max(slots1[i1][0],slots2[i2][0]);
            int overlapEnd = min(slots1[i1][1], slots2[i2][1]);
            overLapContainer = {overlapStart,overlapEnd};

            if(overLapContainer[1] - overLapContainer[0] >= duration)
                return {overLapContainer[0],overLapContainer[0]+duration};

          if(slots1[i1][1] < slots2[i2][1])
              i1++;
          else if(slots1[i1][1] < slots2[i2][0])
              i1++;
          else if(slots1[i1][1] > slots2[i2][1])
              i2++;
          else
          {
              i1++;
              i2++;
          }

        }
        return {};
    }
};

//int main(void)
//{
//    vector<vector<int>> slots1 = {{10,50},{60,120},{140,210}};
//    vector<vector<int>> slots2 = {{0,15},{60,70}};
////    vector<vector<int>> slots1 = {{0,2}};
////    vector<vector<int>> slots2 = {{1,3}};
//    int duration = 2;
//    Solution().minAvailableDuration(slots1,slots2,duration);
//}
