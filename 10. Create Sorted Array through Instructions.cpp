#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int createSortedArray(vector<int>& instructions)
    {
        int result = 0;
        vector<int> sortedInstructions = instructions;
        sort(sortedInstructions.begin(), sortedInstructions.end());
        vector<int>::iterator lessThan;
        vector<int>::iterator greaterThan;
        for(auto it = instructions.rbegin(); it!=instructions.rend(); it++)
        {
            lessThan = lower_bound(sortedInstructions.begin(), sortedInstructions.end(), *it);
           
            greaterThan = upper_bound(sortedInstructions.begin(), sortedInstructions.end(), *it);

            int leftSideDistance = lessThan - sortedInstructions.begin() ;
            int rightSideDistance = (sortedInstructions.end()  - greaterThan);
            result += min(leftSideDistance, rightSideDistance);
            sortedInstructions.erase(lessThan);
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> instructions = { 1,2,3,6,5,4 };
//    Solution obj;
//    obj.createSortedArray(instructions);
//}
