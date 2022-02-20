#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;

int solution(vector<int> &A)
{
    sort(A.begin(), A.end());

    int count  =0;
    for(int i = 0; i < A.size();i++)
    {
        count+= abs(A[i] - (i+1));
    }
    return count;
}
//
//int main(void)
//{
//    vector<int> nums = {6,2,3,5,6,3};
//    cout<<solution(nums)<<endl;
//    vector<int> nums1 = {2,3,3};
//    cout<<solution(nums1)<<endl;
//    vector<int> nums2 = {2,1,4,4};
//    cout<<solution(nums2)<<endl;
//}

