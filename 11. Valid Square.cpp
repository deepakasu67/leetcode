#include<iostream>
#include<math.h>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    float distance(int x1, int y1, int x2, int y2)
    {
        // Calculating distance 
        return sqrt(pow(x2 - x1, 2) +
            pow(y2 - y1, 2) * 1.0);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        set<vector<int>> sortedCordinate;
        sortedCordinate.insert(p1);
        sortedCordinate.insert(p2);
        sortedCordinate.insert(p3);
        sortedCordinate.insert(p4);
        if (sortedCordinate.size() != 4)
            return false;
        vector<vector<int>> vectSortedCoordinated(sortedCordinate.begin(), sortedCordinate.end());
        float d1 = distance(vectSortedCoordinated[0][0],
                            vectSortedCoordinated[0][1],
                            vectSortedCoordinated[1][0],
                            vectSortedCoordinated[1][1]);

        float d2 = distance(vectSortedCoordinated[0][0],
                            vectSortedCoordinated[0][1],
                            vectSortedCoordinated[2][0],
                            vectSortedCoordinated[2][1]);

        float d3 = distance(vectSortedCoordinated[3][0],
                            vectSortedCoordinated[3][1],
                            vectSortedCoordinated[1][0],
                            vectSortedCoordinated[1][1]);

        float d4 = distance(vectSortedCoordinated[3][0],
                            vectSortedCoordinated[3][1],
                            vectSortedCoordinated[2][0],
                            vectSortedCoordinated[2][1]);

        if (d1 != d2 || d3 != d2 || d4 != d2)
            return false;

        float dia1 = distance(vectSortedCoordinated[0][0],
                              vectSortedCoordinated[0][1],
                              vectSortedCoordinated[3][0],
                              vectSortedCoordinated[3][1]);

        float dia2 = distance(vectSortedCoordinated[1][0],
                              vectSortedCoordinated[1][1],
                              vectSortedCoordinated[2][0],
                              vectSortedCoordinated[2][1]);

        if (dia1 != dia2)
            return false;

        return true;
    }
};

//int main(void)
//{
//    vector<int> p1 = {0,0};
//    vector<int> p2 = {1,1};
//    vector<int> p3 = {1,0};
//    vector<int> p4 = {1,1};
//    Solution obj;
//    cout << obj.validSquare(p1, p2, p3, p4);
//}