#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for_each(nums.begin(), nums.end(), [&](int nums)
            {
                if (pq.size() > k)
                    pq.pop();
                pq.push(nums);
            });
        return pq.top();
    }
};