#include<iostream>
#include"LinkedList.h"
#include<vector>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        vector<int> countOfEachNumber(201, 0);
        ListNode* temp = head;
        while(temp != nullptr)
        {
            countOfEachNumber[temp->val + 100]++;
            ListNode* nodeTobedelete = temp;
            temp = temp->next;
            free(nodeTobedelete);
        }
        ListNode* root = nullptr;
        ListNode* end = nullptr;
        for(int i = 0 ;i < countOfEachNumber.size(); i++)
        {
            if (countOfEachNumber[i] == 1)
            {
                if (root == nullptr)
                {
                    root = new ListNode(i - 100);
                    end = root;
                }
                else
                {
                    end->next = new ListNode(i - 100);
                    end = end->next;
                }
            }
        }
        return root;
    }
};

//int main(void)
//{
//    int arr[] = { 1,2,3,3,4,4,5 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    ListNode* list = createList(arr, n);
//    Solution obj;
//    obj.deleteDuplicates(list);
//}