//
// Created by Deepak Sahu on 12/30/21.
//
#include <iostream>
#include <string>
#include<unordered_map>
#include <vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names)
    {
        unordered_map<string, int> namesToFreq;

        vector<string> result;
        for(int i = 0 ;i < names.size(); i++)
        {
            auto seenIt = namesToFreq.find(names[i]);

            if(seenIt == namesToFreq.end())
            {
                result.push_back(names[i]);
                namesToFreq[names[i]]++;
            }
            else
            {
                string seenString = seenIt->first;
                int num = seenIt->second;
                string str;
                while(num)
                {
                    str = seenString + "(" + to_string(num) +")";
                    if(!namesToFreq.count(str))
                        break;
                    num++;
                }
                namesToFreq[str]++;
                result.push_back(str);
                seenIt->second = num;
            }
        }
        return  result;
    }
};

//int main(void)
//{
//    vector<string> names = {"pes","fifa","gta","pes(2019)","pes","pes(1)"};
//    Solution().getFolderNames(names);
//
//}
