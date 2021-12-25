#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int vectorSize = nums.size();
        int sum = vectorSize* (vectorSize + 1) / 2;
        for (auto const& n : nums)
        {
            sum -= n;
        }
        return sum;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> v = { 9,6,4,2,3,5,7,0,1 };
//    obj.missingNumber(v);
//}