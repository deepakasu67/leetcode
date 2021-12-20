#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        set<string> uniqEmail;
        for (int i = 0; i < emails.size(); i++)
        {
            string email = emails[i];
            int idx = email.find('@');
            string localName = email.substr(0, idx);
            string localNameAfterOperation;
            for (char ch : localName)
            {
                if (ch == '.')
                    continue;
                if (ch == '+')
                    break;
                localNameAfterOperation += ch;
            }
            localNameAfterOperation += email.substr(idx);
            uniqEmail.insert(localNameAfterOperation);
        }
        return uniqEmail.size();
    }
};
//
//int main(void)
//{
//    vector<string> emails = { "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com" };
//    Solution obj;
//    obj.numUniqueEmails(emails);
//}