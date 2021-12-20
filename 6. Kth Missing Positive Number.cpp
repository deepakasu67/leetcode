#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int l = 0, r = A.size(), m;
        while (l <=  r) {
            m = (l + r) / 2;
            if (A[m] - 1 - m < k)
                l = m + 1;
            else
                r = m - 1;
        }
        return l + k;
    }
};

//int main(void)
//{
//    vector<int> arr = { 1,10,21,22,25 };
//    Solution obj;
//    cout<<obj.findKthPositive(arr, 9);
//}