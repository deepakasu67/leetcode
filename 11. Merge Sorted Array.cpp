#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int insertPtr = nums1.size() - 1;
        int tillNowLargestOfNum1 = m - 1;
        int tillNowLargestOfNum2 = n - 1;

        //start filling from back
        while(tillNowLargestOfNum1 != -1 && tillNowLargestOfNum2 != -1)
        {
            if(nums1[tillNowLargestOfNum1] > nums2[tillNowLargestOfNum2])
            {
                nums1[insertPtr] = nums1[tillNowLargestOfNum1];
                tillNowLargestOfNum1--;
            }
            else
            {
                nums1[insertPtr] = nums2[tillNowLargestOfNum2];
                tillNowLargestOfNum2--;
            }
            insertPtr--;
        }

        //insert rest of smaller elements from nums2;
        while(tillNowLargestOfNum2 != -1)
        {
            nums1[insertPtr] = nums2[tillNowLargestOfNum2];
            tillNowLargestOfNum2--;
            insertPtr--;
        }
    }
};

//int main(void)
//{
//    vector<int> nums1 = { 2,0 };
//    vector<int> nums2 = { 1 };
//    int m = 1;
//    int n = 1;
//    Solution obj;
//    obj.merge(nums1, m, nums2, n);
//}