#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    //Brute-force
    //int atMostGivenDigitSetUtil(vector<string>& digits, int n, int countOfDigit, long number, int totalDigit, unordered_map<long, int>& dp)
    //{
    //    if(totalDigit == countOfDigit)
    //    {
    //        if(number <= n)
    //        {
    //            return 0;
    //        }
    //    }
    //    if(dp.find(number) != dp.end())
    //    {
    //        return dp[number];
    //    }
    //    int validNumberCount = 0;
    //    
    //    for(int i =0 ;i < digits.size(); i++)
    //    {
    //        long num = number * 10l + stol(digits[i]);
    //        if(num <= n)
    //        {
    //            validNumberCount += ( atMostGivenDigitSetUtil(digits, n, countOfDigit + 1, num, totalDigit,dp) + 1);
    //        }
    //    }
    //    dp[number] =  validNumberCount;
    //    return dp[number];
    //}
    //int atMostNGivenDigitSet(vector<string>& digits, int n)
    //{
    //    int tempOfN = n;
    //    int numOfDigits = 0;
    //    while(tempOfN)
    //    {
    //        numOfDigits++;
    //        tempOfN /= 10;
    //    }
    //    unordered_map<long, int> dp;
    //    return atMostGivenDigitSetUtil(digits, n, 0, 0, numOfDigits, dp);
    //}
    //Brute force

        int find_digs(int a) {
            int ans = 0;
            while (a > 0) {
                a /= 10;
                ans++;
            }
            return ans;
        }

        int helper(vector<string>& digits, string num) {
            int ans = 0;
            int i = 0;

            if (num.length() == 0)
                return 1;

            while (i < digits.size() && stoi(digits[i]) < (num[0] - '0')) {
                ans += pow(digits.size(), num.length() - 1);    /// Adding numbers that start with lesser most significant digit
                i++;
            }
            if (i < digits.size() && stoi(digits[i]) == (num[0] - '0')) {
                ans += helper(digits, num.substr(1));   /// calling recursion to find result of numbers that start with the same most significant digit.
            }

            return ans;

        }


        int atMostNGivenDigitSet(vector<string>& digits, int n) {

            int ans = 0;

            int d = find_digs(n);    /// number of digits in the number n

            for (int i = 1; i <= d - 1; i++) {
                ans += pow(digits.size(), i);    /// Addding the number of numbers which have less than d digits
            }

            string num = "";
            while (n > 0) {
                num += to_string(n % 10);
                n /= 10;
            }
            reverse(num.begin(), num.end());   /// converting n to string

            ans += helper(digits, num);    /// helper function finds count of numbers strictly less than num

            return ans;

        }
};

//int main(void)
//{
//    vector<string> digits = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
//    Solution obj;
//    obj.atMostNGivenDigitSet(digits, 74546987);
//}
