#include<iostream>
#include<unordered_map>
#define MAXN   100000001  
using namespace std;
int spf[MAXN];
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 0, r = num / 2;
        while (l <= r) {
            double mid = l + (r - l) / 2;
            //cout << mid << endl;
            if (mid == num / mid) return true;
            if (mid > num / mid) {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return false;
    }
};
//int main(void)
//{
//	Solution obj;
//	int sum = 0;
//	bool numEnd = false;
//
//    cout << obj.isPerfectSquare(25);
//	
//}