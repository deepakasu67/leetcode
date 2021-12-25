#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        stack<int> st;
        vector<int> result(T.size());
        for(int i = T.size() - 1; i >= 0; i--)
        {
            while(!st.empty())
            {
                if(T[i] < T[st.top()])
                {
                    break;
                }
                st.pop();
            }
            result[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return result;
    }
};

//int main(void)
//{
//    vector<int> temp = { 73, 74, 75, 71, 69, 72, 76, 73 };
//    Solution obj;
//    obj.dailyTemperatures(temp);
//}