#include<iostream>
#include"LinkedList.h"
using namespace std;

class Solution {
public:
    int getDecimalValueUtil(ListNode* node , int &i)
    {
        if(node == nullptr)
        {
            return 0;
        }
        int val = getDecimalValueUtil(node->next, i);
        return val + ((1 << i++) * node->val);
    }
    int getDecimalValue(ListNode* head)
    {
        int i = 0;
        return getDecimalValueUtil(head, i);
    }
};

//int main(void)
//{
//    int a[] = { 1,0,0,1,0,0,1,1,1,0,0,0,0,0,0 };
//    unsigned int n = sizeof(a) / sizeof(a[0]);
//    ListNode* head = createList(a, n);
//    Solution obj;
//    cout<<obj.getDecimalValue(head);   
//}