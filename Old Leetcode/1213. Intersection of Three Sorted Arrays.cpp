#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) 
    {
        int p1, p2, p3;
        p1 = p2 = p3 = 0;
        vector<int> result;
        while (p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size())
        {
            if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3])
            {
                result.push_back(arr1[p1]);
                p1++;
                p2++;
                p3++;
            }
            else
            {
                int minEle = min(min(arr1[p1], arr2[p2]), arr3[p3]);
                if (arr1[p1] == minEle)
                {
                    p1++;
                }
                else if (arr2[p2] == minEle)
                {
                    p2++;
                }
                else
                {
                    p3++;
                }
            }
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> arr1 = { 1,2,3,4,5 };
//    vector<int> arr2 = { 1,2,5,7,9 };
//    vector<int> arr3 = { 1,3,4,5,8 };
//
//    Solution obj;
//    obj.arraysIntersection(arr1, arr2, arr3);
//}