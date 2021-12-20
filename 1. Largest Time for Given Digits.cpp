#include <algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr)
    {
        string str;
        for(auto x : arr)
        {
            str += to_string(x);
        }
        sort(str.begin(), str.end());

        // Keep printing next permutation while there
        // is next permutation
        set<string> set;
        string earliestTime;
        do {
            
            int hour = stoi(str.substr(0, 2));
            if (hour >= 24)
                continue;
            int minute = stoi(str.substr(2, 2));
            if(minute >= 60)
                continue;
            earliestTime = (hour / 10 > 0 ? to_string(hour) : string("0" + to_string(hour)))
                            + ":"
                            + (minute / 10 > 0 ? to_string(minute) : string("0" + to_string(minute)));
        } while (next_permutation(str.begin(), str.end()));

        return earliestTime;
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<int> v = { 2,0,6,6 };
//    cout<<obj.largestTimeFromDigits(v);
//}