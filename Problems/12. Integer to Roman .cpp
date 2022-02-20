//
// Created by Deepak Sahu on 12/26/21.
//

#include<iostream>
#include<string>
#include<map>

using namespace  std;
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> valToSym;
        valToSym[1] = "I";
        valToSym[4] = "IV";
        valToSym[5] = "V";
        valToSym[9] = "IX";
        valToSym[10] = "X";
        valToSym[40] = "XL";
        valToSym[50] = "L";
        valToSym[90] = "XC";
        valToSym[100] = "C";
        valToSym[400] = "CD";
        valToSym[500] = "D";
        valToSym[900] = "CM";
        valToSym[1000] = "M";

        string ans;
        while(num)
        {
            auto it = valToSym.lower_bound(num);
            if(it->first != num )
               --it;
            ans+=it->second;
            num-=it->first;
        }
        return ans;
    }
};
//int main(void)
//{
//    Solution().intToRoman(1994);
//}
