#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int N = nums.size();
        vector<int> result;
        vector<int> a(101);
        vector<int> b(101);
        
        for(int i = 0; i < N; i++){
            a[nums[i]]++;
        }
        for(int i = 1; i < 101; i++){
            b[i] = a[i - 1] + b[i - 1];
        }
        for(int i = 0; i < N; i++){
            result.push_back(b[nums[i]]);
        }
        return result;
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<int> nums = { 8,1,2,2,3};
//    obj.smallerNumbersThanCurrent(nums);
//        
//}