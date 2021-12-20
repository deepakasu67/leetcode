#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid != 0 && nums[mid] == nums[mid - 1])
            {
                if ((mid - l +1) % 2 == 1)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (mid + 1 != nums.size() && nums[mid] == nums[mid + 1])
            {
                if ((r - mid + 1) % 2 == 1)
                {
                    l = mid ;
                }
                else
                {
                    r = mid - 1;
                }
            }   
            else
            {
                return nums[mid];
            }
        }
        return -1;

    }
};

//int main(void)
//{
//    Solution obj;
//    vector<int> v = { 1,1,2,3,3 };
//    cout<<obj.singleNonDuplicate(v);
//}
