//
// Created by Deepak Sahu on 2/28/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        sort(strs.begin(), strs.end());

        int i =0;
        for( i = 0;i < strs.size(); i++)
        {
            if(strs[0][i] != strs.back()[i])
            {
                break;
            }
        }
        return strs[0].substr(0,i);
    }
};

//int main(void)
//{
//    vector<string> strs = {"flower","flow","flight"};
//    cout<<Solution().longestCommonPrefix(strs);
//}