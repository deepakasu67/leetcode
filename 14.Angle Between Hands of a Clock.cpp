#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double angleClock(int hour, int minutes)
    {                                     //12,1,2, 3 , 4 , 5 , 6 , 7, 8  ,9  , 10, 11,
        vector<int> angleForPerfectTime = { 0,30,60,90,120,150,180,210,240,270,300,330 }; //degree of 12:00 -> 0 | 1:00 -> 30 etc
        int degreeInOneMin = 6;

        int degreeCoveredByMinuteHand = abs(minutes*6 - angleForPerfectTime[hour%12]); // this will give the angle travelled by minute
                                                                                      //if hour hand is in the same postition when its is above time
        float angleCoveredByHourHand = static_cast<double>(0.5 * minutes);//if minuteHand moved then hours hand would also have moved

        //if minuteHand crosses the hourHand then we have to take difference of angle covered by minuteHand else we have to add becuase
        //if minuteHand Cross the hourhand then it would have already covered whatever hourhand would have covered. so we we have to remove that angle
        //if minutehand doesn't cross the hour hand then we have to add angle whatever angleCoveredByHourHand;
        double result = (hour * 5)%60 <= minutes? fabs(degreeCoveredByMinuteHand - angleCoveredByHourHand) :
                                                  fabs(degreeCoveredByMinuteHand + angleCoveredByHourHand);
        return result > 180 ? 360 - result : result;
    }
};
//int main(void)
//{
//    Solution obj;
//    obj.angleClock(12, 1);
//}