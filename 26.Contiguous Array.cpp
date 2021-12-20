#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int> count_Index;
        int count = 0;
        count_Index[0] = -1;
        int maxSubArr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] == 0 ? --count : ++count;
            if (count_Index.find(count) != count_Index.end())
            {
                maxSubArr = max(maxSubArr, i - count_Index[count]);
            }
            else
                count_Index[count] = i;
        }
        return maxSubArr;
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> a = { 1,1,1,1,0,0,0,0 };
//    obj.findMaxLength(a);
//}