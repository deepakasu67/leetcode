#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int bSearch(vector<int>& c, int low, int high)
    {
        if (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (c[mid] > mid + 1)
            {
                return bSearch(c, mid + 1, high);
            }
            else if (c[mid] < mid + 1)
            {
                return bSearch(c, low, mid - 1);
            }
            else
            {
                return mid + 1;
            }
        }
       return low ;
    }
    int hIndex(vector<int>& citations)
    {
        if (citations.empty())
            return 0;
        reverse(citations.begin(), citations.end());
        int hIndex = bSearch(citations, 0, citations.size() - 1);
        
            return hIndex;
        
    }
};

//int main(void)
//{
//    vector<int> citations = { 1 }; //5
//    Solution obj;
//    obj.hIndex(citations);
//}