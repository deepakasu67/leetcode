#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        //if x is already present in nums then return 1
        if (find(nums.begin(), nums.end(), x) != nums.end())
            return 1;

        vector<int> sumOfIthElementsFromBack(nums.size(),0);
        sumOfIthElementsFromBack[nums.size() - 1] = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            sumOfIthElementsFromBack[i] = nums[i] + sumOfIthElementsFromBack[i + 1];
        }

        //if x is greater than sum of all elements then it is impossible to reduce it to 0
        if (x > sumOfIthElementsFromBack[0])
            return -1;

        int minimumSum = *min_element(sumOfIthElementsFromBack.begin(), sumOfIthElementsFromBack.end());

        //if x is less than minimum of all prefix sum then after subtracting the minimum only gives -ve
        //(larger than this will give more -ve)
        if (x < minimumSum)
            return -1;

        unordered_map<int, int> sumOfIthElementsFromFront;
        auto it = sumOfIthElementsFromFront.insert(make_pair(nums[0], 0));
        for(int i = 1; i < nums.size(); i++)
        {
            int sum = (it.first)->first + nums[i];
            it = sumOfIthElementsFromFront.insert(make_pair(sum, i));

        }
        int minOpsToReduceXToZero = INT_MAX;
        int sizeOfNums = sumOfIthElementsFromBack.size();
        for(int i = sizeOfNums - 1; i >= 0; i--)
        {
            int restOfNum = abs(x - sumOfIthElementsFromBack[i]);
            if(restOfNum == 0)
            {
                minOpsToReduceXToZero = min(minOpsToReduceXToZero, sizeOfNums - i);
            }
            else
            {
                if(sumOfIthElementsFromFront.find(restOfNum) != sumOfIthElementsFromFront.end())
                {
                    //take minimum operation when there is no overlapping
                    if(sumOfIthElementsFromFront[restOfNum] < i)
                        minOpsToReduceXToZero = min(minOpsToReduceXToZero, sumOfIthElementsFromFront[restOfNum] + 1  + (sizeOfNums - i));
                }
            }
        }
        return minOpsToReduceXToZero == INT_MAX ? -1:minOpsToReduceXToZero;
    }
};

//int main(void)
//{
//    vector<int> nums = { 1,1,4,2,3 };
//    Solution obj;
//    obj.minOperations(nums, 5);
//}