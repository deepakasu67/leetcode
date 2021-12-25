#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) 
    {
        if (arr.size() == 0)
            return 0;

        if (arr.size() == 1)
            return arr[0].length();

        vector<vector<int>> strsCount(arr.size(), vector<int>(26, 0));
        for (int j = 0; j < arr.size(); j++)
        {
            string str = arr[j];
            for (int i = 0; i < str.length(); i++)
            {
                strsCount[j][(int)str[i] - (int)'a']++;
            }
        }

        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                bool duplicate = false;
                for (int l = 0; l < 26; l++)
                {
                    if (strsCount[i][l] != 0 && strsCount[j][l]!=0)
                    {
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate)
                {
                    maxLength = max((int)arr[i].size() + (int)arr[j].size(), maxLength);
                }
            }
        }
        return maxLength;
    }
};

//int main(void)
//{
//    vector<string> arr = { "abcdefghijklmnopqrstuvwxyz"};
//    Solution obj;
//    obj.maxLength(arr);
//}