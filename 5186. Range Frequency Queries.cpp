#include<iostream>
#include<unordered_map>
#include <algorithm>
using namespace std;

class RangeFreqQuery {
    unordered_map<int, vector<int>> frequencyToIndices;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
        {
            frequencyToIndices[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) 
    {
        return upper_bound(frequencyToIndices[value].begin(), frequencyToIndices[value].end(), right)
            - lower_bound(frequencyToIndices[value].begin(), frequencyToIndices[value].end(), left);
    }
};

//int main(void)
//{
//    vector<int> arr = { 12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56 };
//    RangeFreqQuery obj(arr);
//    cout << obj.query(1,2,4);
//    cout << obj.query(0,11,33);
//    cout << obj.query(9,10,12);
//    cout << obj.query(9,10,56);
//}