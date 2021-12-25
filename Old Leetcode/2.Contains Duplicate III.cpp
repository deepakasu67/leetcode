#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        multiset<int> setOfKElements;
        multiset<int>::iterator insertedElementPlace;
        for(int i = 0; i < nums.size(); i++)
        {
            if(setOfKElements.size() < k + 1)
            {
                insertedElementPlace =  setOfKElements.insert(nums[i]);
            }
            else
            {
                setOfKElements.erase(nums[i - k - 1]);
                insertedElementPlace = setOfKElements.insert(nums[i]);
            }
            auto temp = insertedElementPlace;
            if(insertedElementPlace != setOfKElements.begin() && abs(*(--temp) - nums[i]) <= t)
            {
                return true;
            }
            if (next(insertedElementPlace) != setOfKElements.end() && abs(*(++insertedElementPlace) - nums[i]) <= t)
                return true;
        }
        return false;
    }
};
//
//int main(void)
//{
//    Solution Obj;
//    vector<int> vec = { -3,3,-6 };
//    cout<<Obj.containsNearbyAlmostDuplicate(vec,2,3);
//}