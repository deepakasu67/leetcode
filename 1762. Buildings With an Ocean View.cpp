#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights)
    {
        if (heights.empty())
            return {};
        vector<int> result;
        int maxTillNow = 0;
        for(int i = heights.size() - 1; i >= 0 ;i--)
        {
            if(heights[i] > maxTillNow)
            {
                result.push_back(i);
            }
            maxTillNow = max(heights[i], maxTillNow);
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> heights= { 4,2,3,1 };
//    Solution obj;
//    obj.findBuildings(heights);
//}