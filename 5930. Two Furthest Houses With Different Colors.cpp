#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int maxDi = INT_MIN;
        for (int i = 0; i < colors.size(); i++)
        {
            for (int j = i; j < colors.size(); j++)
            {
                if (colors[i] != colors[j])
                    if (abs(i - j) > maxDi)
                    {
                        maxDi = abs(i - j);
                    }
            }
        }
        return maxDi;
    }
};
//int main()
//{
//    vector<int> nums = { 0,1 };
//    cout<<Solution().maxDistance(nums);
//}