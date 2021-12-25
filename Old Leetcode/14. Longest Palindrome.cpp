#include <algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
#include <set>
using namespace std;
class Solution {   
public:
    int longestPalindrome(string str) {
		unordered_map<char,int> charfreqMap;
		int count = 0;
		int countOddMax = 0;
		for(char c: str)
		{
			charfreqMap[c]++;
		}
		for(auto it:charfreqMap)
		{
			if(it.second%2 == 1)
			{
				countOddMax = max(countOddMax, it.second);
			}
		}
		bool alreadCounted = true;
		for (auto it : charfreqMap)
		{
			if (it.second == countOddMax && alreadCounted == true)
			{
				count += countOddMax;
				alreadCounted = false;
			}
			else if (it.second % 2 == 1)
			{
				count += it.second - 1;
			}
			else
				count += it.second;
		}
		return count;
    }
};
//int main(void)
//{
//	string str = "abccccdd";
//	Solution obj;
//	cout<<obj.longestPalindrome(str);
//}