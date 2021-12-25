//https://youtu.be/8tDM_pfmlrw
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() == 0) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> result(nums.size(), vector<int>());
    int max_len = 1, max_idx = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {
        result[i].push_back(nums[i]);
        int j = i + 1;
        int _max = 0, _max_idx = i;
        while (j < nums.size()) {
            if (nums[j] % nums[i] == 0 && result[j].size() > _max) {
                _max = result[j].size();
                _max_idx = j;
            }
            j++;
        }
        if (_max_idx != i) {
            result[i].insert(result[i].end(), result[_max_idx].begin(), result[_max_idx].end());
            if (_max + 1 > max_len) {
                max_len = _max + 1;
                max_idx = i;
            }
        }
    }
    return result[max_idx];
}