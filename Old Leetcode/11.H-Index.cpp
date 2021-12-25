#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    //int binarySearch(int low, int high, vector<int> citations)
    //{
    //    if(low <= high)
    //    {
    //        int mid = low + (high - low) / 2;
    //        if(citations[mid] < mid)
    //        {
    //            return binarySearch(low, mid - 1,citations); 
    //        }
    //        else if(citations[mid] > mid)
    //        {
    //            return binarySearch(mid + 1, high, citations);
    //        }
    //        else
    //        {
    //            return mid;
    //        }
    //    }
    //    return low;
    //}
    //int hIndex(vector<int>& citations) {
    //    sort(begin(citations), end(citations), greater<int>());
    //    return binarySearch(0, citations.size() - 1, citations);
    //}
    //
    // Time: O(n)  space:O(n)
    int hIndex(vector<int>& citations)
    {
        vector<int> bucket(citations.size() + 1);
        for(int i = 0; i < citations.size();i++)
        {
            if (citations[i] >= citations.size())
            {
                bucket[citations.size()]++;
            }
            else
                bucket[citations[i]]++;
        }
        int count = 0;
        for(int i = bucket.size() - 1; i >= 0; i--)
        {
            count += bucket[i];
            if (i <= count)
            {
                return i;
            }
        }
        return 0;
    }
};
//int main(void)
//{
//    vector<int> citations = { 1,0,6,1,5 };
//    Solution obj;
//    cout<<obj.hIndex(citations);
//}