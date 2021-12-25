#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) 
    {
        int origCapacitA = capacityA;
        int origCapacityB = capacityB;
        int a = 0;
        int b = plants.size() - 1;
        int refile = 0;
        while (a <= b)
        {
            if (a == b)
            {
                if (plants[a] > capacityA && plants[b] > capacityB)
                {
                    refile++;
                }
                break;
            }

            if (plants[a] > capacityA)
            {
                capacityA = origCapacitA;
                refile++;
            }
            if (plants[b] > capacityB)
            {
                capacityB = origCapacityB;
                refile++;
            }

            
            capacityA -= plants[a];
            capacityB -= plants[b];

            a++, b--;

        }
        return refile;
    }
};
//
//int main(void)
//{
//    vector<int> plants = { 2,1,1 };
//   
//    cout<<Solution().minimumRefill(plants, 2, 2);
//}