#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int trail = 0;
        int forward = 0;
        int currentSum = nums[forward];
        int min = INT_MAX;
        for (; forward < nums.size(); )
        {
            if (currentSum < s)
            {
                forward++;
                if (forward < nums.size())
                    currentSum += nums[forward];
                else
                    break;
            }
            if (currentSum >= s)
            {
                if (min > (forward - trail) + 1)
                {
                    min = (forward - trail) + 1;
                }
                currentSum -= nums[trail];
                trail++;
            }
        }
        return  min % INT_MAX;
    }
};
//int main(void)
//{
//    vector<int> v = { 2,3,1,2,4,7 };
//    Solution obj;
//    cout<<obj.minSubArrayLen(7,v);
//    cout << 2 % 1 << 6 % 1;
//}