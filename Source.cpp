#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool checkIfTrianglePossible(long long int a, long long int b, long long int c) {
	if ((long long int)(long long int)a + (long long int)b > (long long int)c && 
		(long long int)(long long int)b + (long long int)c > (long long int)a &&
		(long long int)(long long int)c + (long long int)a > (long long int)b)
		return true;
	return false;
}

vector<int> canMakeTriangle(vector<int> arr) {
	vector<int> result;
	for (int i = 2; i < arr.size(); i++) {
		if (checkIfTrianglePossible(arr[i - 2], arr[i - 1], arr[i])) {
			result.push_back(1);
		}
		else {
			result.push_back(0);
		}
	}
	return result;
}

//int main() {
//	vector<int> arr;
//	arr.push_back(1000000000);
//	arr.push_back(1000000000);
//	arr.push_back(1000000000);
//	arr.push_back(1000000000	);
//	vector<int> arr2;
//	arr2.push_back(2);
//	arr2.push_back(10);
//	arr2.push_back(2);
//	arr2.push_back(10);
//	arr2.push_back(2);
//	vector<int> ans = canMakeTriangle(arr);
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << endl;
//	}
//	return 0;
//}