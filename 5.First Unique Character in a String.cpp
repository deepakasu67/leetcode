#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int arr[26] = { 0 };
    int i = 0;

    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (s == "")return -1;

        for (;i < s.size();i++)
            arr[s[i] - 'a']++;

        for (i = 0;i < s.size();i++)
            if (arr[s[i] - 'a'] == 1)return i;


        return -1;
    }
};
//int main(void)
//{
//    auto f = []() { cout << "false "; return false; };
//    auto t = []() { cout << "true "; return true; };
//    if (f() && t())
//        cout << "result";
//}
