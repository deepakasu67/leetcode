#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {//Greedy
public: //Time/Space: O(N^2); O(1)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
            });
        //Note: The following operation is O(N^2)
        for (int i = 0; i < people.size(); i++) {
            auto p = people[i];
            if (p[1] != i) {
                people.erase(people.begin() + i);
                people.insert(people.begin() + p[1], p);
            }
        }
        return people;

    }
};
//int main(void)
//{
//    vector<vector<int>> v = { {7, 0},{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };
//    Solution obj;
//    obj.reconstructQueue(v);
//}