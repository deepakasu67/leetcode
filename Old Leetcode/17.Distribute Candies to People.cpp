#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> peoples(num_people,0);
        int numberOfCandies = 1;
        int people = 0;
        while(candies > 0)
        {
            candies = candies - numberOfCandies;
            if (candies < 0)
            {
                peoples[people % num_people] += candies + numberOfCandies;
            }
            else
            {
                peoples[people % num_people] += numberOfCandies;
            }
            numberOfCandies++;
            people++;
        }
        return peoples;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.distributeCandies(10, 3);
//}