#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k)
    {
        vector<bool> visited(n,false);
        visited[0] = true;
        vector<int> result;
        result.push_back(1);
        int sign = 1;
        // first create K distinct numbers by +k + result.back(),-(k-1) + + result.back() ,+(k-2) + result.back()
        for (int i = 1; i <= n; i++)
        {
            int nextElem = sign * (k) + result.back();
            result.push_back(nextElem);
            visited[nextElem - 1] = true;
            k--;
            if (k <= 0)
            {
                break;
            }
            sign = -1 * sign;
        }     
        // add all the distinct number which are left from above number from 1-n
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] == false)
                result.push_back(i + 1);
        }
        return result;
    }
};

//int main(void)
//{
//    Solution obj;
//    obj.constructArray(4, 2);
//}