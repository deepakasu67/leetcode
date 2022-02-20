#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long bioHazard(int n, vector<int> allergic, vector<int> poisnous)
{
    unordered_map<int, int> mp;

    for(int i =0; i < allergic.size(); i++)
    {
        int left = max(allergic[i],poisnous[i]);
        int right = min(allergic[i],poisnous[i]);
        if(mp.count(right))
        {
            int cur = mp.find(right)->second;
            mp[right] = max(left, cur);
        }
        else
            mp[right] = left;
    }

    long res =0;
    int end = 0;
    for(int i =0;i < n; i++)
    {
        if( i == 0)
            end=0;
        while(end < n && (!mp.count(end) || mp.find(end)->second > i))
        {
            end++;
        }
        res += end -i - 1;
    }
    return res+1;
}
//
//int main(void)
//{
////    int n = 3;
////    vector<int> allergic = {2,1,3};
////    vector<int> poisnous = {3,3,1};
//    int n = 8;
//    vector<int> allergic = {2,3,4,3};
//    vector<int> poisnous = {8,5,6,4};
//    cout<<bioHazard(n, allergic, poisnous);
//}
