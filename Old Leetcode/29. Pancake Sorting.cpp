#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A)
    {
        vector<int>  result;
        if (is_sorted(A.begin(), A.end()))
        {
            return {};
        }
        int numTOBeFind = A.size();

        while(numTOBeFind >= 2)
        {
            int idxOfNumToBeFind = find(A.begin(), A.end(), numTOBeFind) - A.begin();
            if (idxOfNumToBeFind + 1 != numTOBeFind)
            {
                if (idxOfNumToBeFind != 0)
                {
                    result.push_back(idxOfNumToBeFind + 1);
                    reverse(A.begin(), A.begin() + idxOfNumToBeFind + 1);
                }
                result.push_back(numTOBeFind);
                reverse(A.begin(), A.begin() + numTOBeFind);
            }
            numTOBeFind--;
        }
        return result;
    }
};
//int main(void)
//{
//    vector<int> nums = { 3,2,4,1 };
//    Solution obj;
//    obj.pancakeSort(nums);
//}