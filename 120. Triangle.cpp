#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        for (int i = size - 2; i >= 0; i--)
        {
            for(int j = 0 ;j < triangle[i].size(); j++)
            {
                int left = triangle[i + 1][j];
                int right = triangle[i + 1][j + 1];
                triangle[i][j] += min(left, right);
            }
        }
        return triangle[0][0];
    }
};
//int main(void)
//{
//    //vector<vector<int>> triangles = {
//    //        {2} ,
//    //        {3, 4},
//    //        {6, 5, 7},
//    //        {4, 1, 8, 3}
//    //};
//    vector<vector<int>> triangles = { {2},{3, 4},{6, 5, 9},{4, 4, 8, 0} };
//
//    Solution obj;
//    cout<<obj.minimumTotal(triangles);
//}