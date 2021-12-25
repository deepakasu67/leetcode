#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int noOfBoatRequired = 0;
        while(left < right)
        {
            int leftNumber = people[left];
            int rightNumber = people[right];

            if((leftNumber + rightNumber) <= limit)
            {
                left++;
                right--;
            }
            else 
            {
                right--;
            }
            noOfBoatRequired++;
        }
        return left == right ? noOfBoatRequired+1 : noOfBoatRequired;
    }
};

//int main(void)
//{
//    vector<int> peoplesWeight = { 1,2 };
//    Solution obj;
//    cout<<obj.numRescueBoats(peoplesWeight, 2);
//}