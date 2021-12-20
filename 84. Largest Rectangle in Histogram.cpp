#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    vector<int> previousSmallest;
    vector<int> nextSmallest;
public:
    vector<int> previousSmallestElement(vector<int>& heights)
    {
        stack<int> st;
        previousSmallest.resize(heights.size());
        st.push(-1);
        for (int i = 0; i < heights.size(); i++)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            previousSmallest[i] = st.top() + 1;
            st.push(i);
        }
        return previousSmallest;
    }

    vector<int> nextSmallestElement(vector<int>& heights)
    {
        stack<int> st;
        nextSmallest.resize(heights.size());
        st.push(heights.size());
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (st.top() != heights.size() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            nextSmallest[i] = st.top() - 1;
            st.push(i);
        }
        return nextSmallest;
    }

    int largestRectangleArea(vector<int>& heights) 
    {
        nextSmallestElement(heights);
        previousSmallestElement(heights);
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            int area = heights[i] * (this->nextSmallest[i] - previousSmallest[i] + 1);
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
    }
};

//int main(void)
//{
//    vector<int> height = { 1,1 };
//    Solution().largestRectangleArea(height);
//}