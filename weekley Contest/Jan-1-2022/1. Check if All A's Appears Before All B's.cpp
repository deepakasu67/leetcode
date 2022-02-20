//
// Created by Deepak Sahu on 1/1/22.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkString(string s) {

        size_t idxOfFirstB = s.find('b');


        for(int i =idxOfFirstB ; i  < s.length(); i++)
        {
            if(s[i] == 'a')
                return false;
        }
        return true;
    }
};

//int main(void)
//{
//    cout<<boolalpha;
//    cout<<Solution().checkString("aaabb")<<endl;
//    cout<<Solution().checkString("baaabb")<<endl;
//    cout<<Solution().checkString("bbb")<<endl;
//    cout<<Solution().checkString("bbbaaa")<<endl;
//    cout<<Solution().checkString("aaaa")<<endl;
//    cout<<Solution().checkString("a")<<endl;
//    cout<<Solution().checkString("b")<<endl;
//
//}