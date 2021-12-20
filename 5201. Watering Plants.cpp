#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int origCapacity) 
    {
        int steps = 0;
        int capacity = origCapacity;
        for (int i = 0; i < plants.size(); i++)
        {
            if (plants[i] <= capacity)
            {
                capacity -= plants[i];
                steps++;
            }
            else
            {
                int gotoRiver = i;
                capacity = origCapacity;
                int cameToPlant = i + 1;
                capacity -= plants[i];
                steps += (gotoRiver + cameToPlant);
            }
        }
        return steps;
    }
};

//int main(void)
//{
//    vector<int> nums = { 7,7,7,7,7,7,7 };
//    cout<<Solution().wateringPlants(nums,8);
//}