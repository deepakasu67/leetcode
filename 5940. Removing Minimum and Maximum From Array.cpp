#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();
        int minIdx = min_element(nums.begin(), nums.end())-nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        int caseI = 0;
        int caseII = 0;
        if (minIdx > maxIdx)
        {
            swap(minIdx, maxIdx);
        }
         caseI = min(maxIdx + 1, n - minIdx);
            caseII = minIdx + 1 + (n - maxIdx );
            return min(caseI, caseII);

    }
};

//int main(void)
//{
//    vector<int> nums = { 2};
//    cout<<Solution().minimumDeletions(nums);
//}