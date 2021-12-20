#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
class Solution {
public:
    string getPermutation(int n, int k) {
    #define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
        if (n > 9)
            return "";
        if (k < 1)
            return "";
        string input;
        for (int i = 1; i <= n; i++)
        {
            input += to_string(i);
        }
        string result;
        do
        {
            if (k == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    result += input[i];
                }
                break;
            }
            k--;
        } while (next_permutation(input.begin(), input.end()));
        return result;
    }
};
//int main(void)
//{
//    Solution obj;
//    cout<<obj.getPermutation(3,3);
//}