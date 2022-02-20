//
// Created by Deepak Sahu on 1/16/22.
//
#include <iostream>
#include <vector>
using namespace std;

ostream & operator<<(ostream& o, vector<int>& data)
{
    for(int i =0 ; i < data.size(); i++)
    {
        o << data[i]<< " ";
    }
    return o;
}

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int zero = 0;
        int two  = nums.size()-1;

        for(int i = 0 ; i <nums.size() && zero < two;)
        {
            if(nums[i] == 0)
                swap(nums[zero++], nums[i]);
            if (nums[i] == 2)
                swap(nums[two--],nums[i]);
            if(nums[i] == 1)
                i++;
        }
    }
};

//int main(void)
//{
//    vector<int> nums = {2,0,2,1,1,0};
//    cout<<nums<<endl;
//    Solution().sortColors(nums);
//    cout<<nums;
//}