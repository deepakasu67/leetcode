#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
    {
        vector<pair<int, int>> engineerWithEffAndSpeed;
        for(int i =0; i < speed.size(); i++)
        {
            engineerWithEffAndSpeed.push_back({ efficiency[i],speed[i] });
        }
        sort(engineerWithEffAndSpeed.begin(), engineerWithEffAndSpeed.end(), greater<>());

        priority_queue<int, vector<int>, greater<>> minHeap;

        long sumOfSpeed = 0;
        long res = 0;
        for(auto& [eff,speed] : engineerWithEffAndSpeed)
        {
            minHeap.push(speed);
            sumOfSpeed += speed;
            while(minHeap.size() > k)
            {
                sumOfSpeed -= minHeap.top();
                minHeap.pop();
            }
            res = max(res, sumOfSpeed * eff);
        }
        return res % 1000000007;
    }
};

//int main(void)
//{
//    int n = 6, k = 2;
//    vector<int> speed = { 2,10,3,1,5,8 };
//    vector<int> eff = { 5,4,3,9,7,2 };
//    Solution obj;
//
//    obj.maxPerformance(n, speed, eff, k);
//}