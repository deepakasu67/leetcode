//
// Created by Deepak Sahu on 1/8/22.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // Find the next greater element for every element in an array
    vector<int> findNextGreaterElements(vector<int> const &input) {
        int n = input.size();
        vector<int> result(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && input[s.top()] < input[i]) {
                result[s.top()] = input[i];
                s.pop();
            }
            s.push(i);
        }

        return result;
    }

    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> ans = findNextGreaterElements(nums);

        return {ans.begin(), ans.begin()+n};
    }
};

//int main(void) {
////    vector<int> nums = {1,2,3,4,3};
//    vector<int> nums = {5, 4, 3, 2, 1};
//    cout<<Solution().nextGreaterElements(nums);
//}
