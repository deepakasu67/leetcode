#include<iostream>
#include"LinkedList.h"
#include<vector>
using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int sizeOfList = 0;
        ListNode* iter = head;
        vector<ListNode*> ans(k,nullptr);
        while (iter != nullptr)
        {
            sizeOfList++;
            iter = iter->next;
        }

        int partSize = ( sizeOfList / k), extranode = sizeOfList%k;
        
        ListNode* node = head, *prev = nullptr;

        for (int i = 0; node != nullptr && i < k; i++, extranode--)
        {
            ans[i] = (node);
            for (int j = 0; j < partSize + (extranode > 0 ? 1 : 0); j++)
            {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }

        return ans;
    }
};

//int main(void)
//{
//    int arr[] = { 1,2,3 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    ListNode* head = createList(arr, n);
//    Solution obj;
//    obj.splitListToParts(head, 5);
//}