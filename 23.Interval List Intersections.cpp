#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<iterator>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty())
            return { {} };
        multimap<int, int> coordinates;
        vector<vector<int>> result;
        int aSize = A.size();
        int bSize = B.size();
        for (int i = 0, j = 0; i < aSize || j < bSize; i++, j++)
        {
            if (i < aSize)
            {
                coordinates.insert({A[i][0], A[i][1]});
            }
            if (j < bSize)
            {
                coordinates.insert({ B[j][0],B[j][1] });
            }
        }
        for (auto inIt = coordinates.begin(); inIt != coordinates.end(); inIt++)
        {
            auto next = inIt;
            next++;
            auto outIt = next;
            for (; outIt != coordinates.end(); outIt++)
            {
                if (inIt->second >= outIt->first)
                {
                    vector<int> temp = { max(inIt->first, outIt->first), min(inIt->second, outIt->second) };
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};

//int main(void)
//{
//    Solution obj;
//    vector<vector<int>> a = { {1,2} };
//    vector<vector<int>> b = { {15, 17},{18, 20 } };
//    obj.intervalIntersection(a, b);
//}