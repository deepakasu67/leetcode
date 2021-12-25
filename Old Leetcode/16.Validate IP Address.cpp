#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkValidHexaDecimal(char c)
    {
        if (c - '0' >= 0 && c - '0' <= 9)
            return true;
        else if ((c == 'a') ||
            (c == 'b') ||
            (c == 'c') ||
            (c == 'd') ||
            (c == 'e') ||
            (c == 'f') ||
            (c == 'A') ||
            (c == 'B') ||
            (c == 'C') ||
            (c == 'D') ||
            (c == 'E') ||
            (c == 'F'))
            return true;
        else
            return false;
    }
    bool isIPV6(string ip)
    {
        int cnt = count(ip.begin(), ip.end(), ':');
        if (cnt != 8)
            return false;
        string temp;

        for (int i = 0; i < ip.length(); i++)
        {
            if (ip[i] != ':')
            {
                if (checkValidHexaDecimal(ip[i]))
                    temp += ip[i];
                else
                    return false;
            }
            else
            {
                if (temp.empty())
                    return false;
                if (temp.length() > 4)
                    return false;
                temp.clear();
            }
        }
        return true;
    }
    bool isIPV4(string ip)
    {
        int cnt = count(ip.begin(), ip.end(), '.');
        if (cnt != 4)
            return false;
        string temp;

        for (int i = 0; i < ip.length(); i++)
        {
            if (ip[i] != '.')
            {
                if (ip[i] - '0' >= 0 && ip[i] - '0' <= 9)
                    temp += ip[i];
                else
                    return false;
            }
            else
            {
                if (temp.length() > 4)
                    return false;
                int number;
                if (temp.empty())
                    return false;
                else
                    number = stoi(temp);
                if (to_string(number) != temp) 
                {
                    return false;
                }
                if (number > 255)
                {
                    return false;
                }
                temp.clear();
            }
        }
        return true;
    }
    string validIPAddress(string ip) 
    {
        if (ip.empty())
            return "Neither";
        if (ip.find('.') != string::npos && ip.find(':') != string::npos)
        {
            return "Neither";
        }
        else if (ip.find(".") != string::npos)
        {
            if (isIPV4(ip+'.'))
                return "IPv4";
            else
                return "Neither";
        }
        else if (ip.find(":") != string::npos)
        {
            if (isIPV6(ip + ':'))
                return "IPv6";
            else
                return "Neither";
        }
        else
        {
            return "Neither";
        }
    }
};

//int main(void)
//{
//    Solution obj;
//    cout<<endl<<obj.validIPAddress("172.16.254.0");
//    cout << endl << obj.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334");
//    /*cout << endl << obj.validIPAddress("1.0.1.");*/
//    cout << endl << obj.validIPAddress("A.a.aA.2");
//    cout << endl << obj.validIPAddress("2001:0zb8:85a3:0:0:8A2E:0370:7334");
//    cout << endl << obj.validIPAddress("2001:db8:85a3:0::8a2E:0370:7334");
//
//}