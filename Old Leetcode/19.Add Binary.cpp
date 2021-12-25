#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        int sizeA = a.length();
        int sizeb = b.length();
        int carry = 0;
        sizeA--, sizeb--;
        string result;
        while(sizeA >= 0  || sizeb >= 0 || carry)
        {
            int sum = 0;
            if (sizeA >= 0)
                sum += a[sizeA] - '0';
            if (sizeb >= 0)
                sum += b[sizeb] - '0';
            sum+=carry;
            carry = sum / 2;
            result.push_back(static_cast<char>(sum % 2) +'0');
            sizeA--;
            sizeb--;
        }
        
        return string(result.rbegin(), result.rend());
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<obj.addBinary("1", "1");
//}