#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A)
    {
        bool positive = false;
        int i = 0;
        //find wheather it is monotnoc increasing or monotonic decreasing
        for (i = 0; i < A.size() - 1; i++)
        {
            if (A[i + 1] - A[i] > 0)
            {
                positive = true;
                break;
            }
            else if (A[i + 1] - A[i] == 0)
                continue;
            else
                break;
        }
        // if i reached here then all numbers are same
        if (i + 1 == A.size())
        {
            return true;
        }

        for (; i < A.size() - 1; i++)
        {
            if (A[i + 1] - A[i] < 0 && positive == true)
            {
                return false;
            }
            if (A[i + 1] - A[i] > 0 && positive == false)
            {
                return false;
            }
        }
        return true;
    }
};

//
//int main(void)
//{
//    vector<int> nums = { 1,3,2 };
//    Solution obj;
//    obj.isMonotonic(nums);
//}
