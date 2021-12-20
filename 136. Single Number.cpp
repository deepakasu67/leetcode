#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int result = 0;
        for (auto const& n : nums)
        {
            result = result ^ n;
        }
        return result;
    }
};
//int main(void)
//{
//    vector<int> v = { 2,2,1 };
//    Solution obj;
//    cout<<obj.singleNumber(v);
//}