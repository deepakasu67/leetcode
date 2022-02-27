//
// Created by Deepak Sahu on 2/24/22.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        for(int i=0, j =0; i < version1.size() || j < version2.size();)
        {
            int numVer1 = 0;
            int numVer2 = 0;
            if(i < version1.size())
            {
                int idx = version1.find('.', i);
                if(idx != string::npos) {
                    numVer1 = atoi(version1.substr(i, idx - i).c_str());
                    i = idx+1;
                }
                else {
                    numVer1 = atoi(version1.substr(i).c_str());
                    i = version1.size();
                }

            }
            if(j < version2.size())
            {
                int idx = version2.find('.',j);
                if(idx != string::npos) {
                    numVer2 = atoi(version2.substr(j, idx - j).c_str());
                    j = idx  +1;
                }
                else {
                    numVer2 = atoi(version2.substr(j).c_str());
                    j = version2.size();
                }
            }
            if(numVer1 < numVer2)
                return -1;
            if(numVer2 > numVer2)
                return 1;
        }
        return 0;
    }
};

//
//int main(void)
//{
//    string num1 = "0.1";
//    string num2 = "1.1";
//    cout<<Solution().compareVersion(num1,num2);
//}
