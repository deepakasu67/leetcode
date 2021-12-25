#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right) {
            if (height[left] > leftMax) leftMax = height[left];
            if (height[right] > rightMax) rightMax = height[right];
            if (leftMax < rightMax) {
                ans += max(0, leftMax - height[left]);
                left++;
            }
            else {
                ans += max(0, rightMax - height[right]);
                right--;
            }
        }
        return ans;
    }

};
//int main(void)
//{
//    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//    Solution obj;
//    cout<<obj.trap(height);
//}