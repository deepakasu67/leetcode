#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class SparseVector {
public:
    unordered_map<int, int> idxToNonZero;
    SparseVector(vector<int>& nums)
    {
        for(int i= 0; i < nums.size();i++)
        {
            if(nums[i] != 0)
                idxToNonZero[i] = nums[i];
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec)
    {
        int result = 0;
        for(auto it = idxToNonZero.begin(); it != idxToNonZero.end(); it++)
        {
            if(vec.idxToNonZero.find(it->first) != vec.idxToNonZero.end())
            {
                result += (vec.idxToNonZero[it->first] * idxToNonZero[it->first]);
            }
        }
        return result;
    }
};
//int main(void)
//{
//    // Your SparseVector object will be instantiated and called as such:
//    vector<int> nums1 = { 1,0,0,2,3 };
//    vector<int> nums2 = { 0,3,0,4,0 };
//    SparseVector v1(nums1);
//    SparseVector v2(nums2);
//    int ans = v1.dotProduct(v2);
//    cout << ans;
//}
