#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircularUtil(vector<int>& vec)
    {
        int max_so_far, curr_max;
        int min_so_far, curr_min;
        max_so_far = curr_max = vec[0];
        min_so_far = curr_min = vec[0];
        int total_sum = 0 + vec[0];
        for (int i = 1; i < vec.size(); i++)
        {
            curr_max = max(vec[i], curr_max+vec[i]);
            max_so_far = max(curr_max, max_so_far);
            curr_min = min(vec[i], vec[i] + curr_min);
            min_so_far = min(curr_min, min_so_far);
            total_sum += vec[i];
        }
        if (total_sum == min_so_far)
            return max_so_far;
        else
             return max(max_so_far,total_sum - min_so_far);
    }
    int maxSubarraySumCircular(vector<int>& vec) {
        return maxSubarraySumCircularUtil(vec);
    }
};
//int main(void)
//{
//    Solution obj;
//    vector<int> vec = { 1,-2,3,-2 };
//
//    cout<<obj.maxSubarraySumCircular(vec);
//}