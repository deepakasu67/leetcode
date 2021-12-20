//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size() ,false );
        int max = *max_element(begin(candies), end(candies));
        int idx = 0;
        for_each(begin(candies), end(candies),  [&](int &candies)
                                                {
                                                    if ((candies + extraCandies) >= max)
                                                    {
                                                        result[idx] = true;
                                                    }
                                                    idx++;
                                                });
        return result;
    }
};

//int main(void)
//{
//    vector<int> candies = {12,1,12};
//    Solution obj;
//    obj.kidsWithCandies(candies, 10);
//}