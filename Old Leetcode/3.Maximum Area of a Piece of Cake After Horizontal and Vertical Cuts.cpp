#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define mod 1000000007

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.push_back(h);
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxDiffOfTwoHorizontalCuts = 0;
        for (int i = 0; i < horizontalCuts.size() - 1; i++)
        {
            maxDiffOfTwoHorizontalCuts = max(maxDiffOfTwoHorizontalCuts, abs(horizontalCuts[i + 1] - horizontalCuts[i]));
        }

        int maxDiffOfTwoVerticalCuts = 0;
        for (int i = 0; i < verticalCuts.size() - 1; i++)
        {
            maxDiffOfTwoVerticalCuts = max(maxDiffOfTwoVerticalCuts, abs(verticalCuts[i + 1] - verticalCuts[i]));
        }
        return (long)((long)(maxDiffOfTwoHorizontalCuts % mod) * (long)(maxDiffOfTwoVerticalCuts % mod)) % mod;
    }
};

//int main(void)
//{
//    vector<int> horizontalCuts = {  };
//    vector<int> verticalCuts = { 1,3 };
//    Solution obj;
//    obj.maxArea(5,4,horizontalCuts,verticalCuts);
//}