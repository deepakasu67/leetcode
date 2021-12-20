#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isCollinear(float &prevSlope, int x1, int y1, int x2, int y2)
    {
        float currSlope = (float(y2 - y1) / float(x2 - x1));
        bool isCollinear  = (prevSlope == currSlope);
        prevSlope = currSlope;
        return isCollinear;

    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float prevSlope = float(coordinates[1][1] - coordinates[0][1])
                        / float(coordinates[1][0] - coordinates[0][0]);
        for (int i = 1; i < coordinates.size() - 1; i++)
        {
            if (!isCollinear(prevSlope, coordinates[i][0], coordinates[i][1], coordinates[i + 1][0], coordinates[i + 1][1]))
            {
                return false;
            }
            
        }
        return true;
    }
};

//int main(void)
//{
//    vector<vector<int>> coordinates = { {1,1 }, { 2,2 }};
//    Solution obj;
//    obj.checkStraightLine(coordinates);
//}