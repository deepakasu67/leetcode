//
// Created by Deepak Sahu on 1/1/22.
//
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        std::sort(asteroids.begin(), asteroids.end());
        int idx = lower_bound(asteroids.begin(), asteroids.end(),mass) - asteroids.begin();

        int sum = accumulate(asteroids.begin(), asteroids.begin() + idx,mass);

        for(int i =idx; i < asteroids.size(); i++)
        {
            if(sum >= asteroids[i])
            {
                sum+= asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;

    }
};

//int main(void)
//{
//    cout<<boolalpha;
//    vector<int> asteroid= {4,9,23,4};
//    cout<<Solution().asteroidsDestroyed(5, asteroid)<<endl;
//}
