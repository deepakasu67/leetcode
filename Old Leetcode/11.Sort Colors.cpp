#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIdx = 0;
        int twoIdx = nums.size() - 1;
        int idx = 0;
        while (idx <= twoIdx)
        {
            if (nums[idx] == 2)
            {
                if (nums[twoIdx] == 2)
                {
                    while (idx < twoIdx && nums[--twoIdx] == 2);
                }
                if(idx >= twoIdx )
                    break;
                swap(nums[idx], nums[twoIdx]);
                twoIdx--;
            }
            if (nums[idx] == 0)
            {
                swap(nums[idx],nums[zeroIdx]);
                zeroIdx++;
            }
            idx++;
        }
    }
};
//int main(void)
//{
//    vector<int> v = { 2,1,2 };
//    Solution obj;
//    obj.sortColors(v);
//}