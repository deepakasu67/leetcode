//
// Created by Deepak Sahu on 2/4/22.
//
#include <iostream>
#include <vector>
#include "CreateATreeWithArray.h"
#include "LinkedList.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& list, int left, int right)
    {
        if(left > right)
            return nullptr;
        if(left== right)
            return new TreeNode(list[left]);

        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(list[mid]);
        root->left = sortedArrayToBST(list, left, mid-1);
        root->right = sortedArrayToBST(list, mid + 1, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> list;
        while(head != nullptr)
        {
            list.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(list, 0, list.size()-1);
    }
};

//int main(void)
//{
//    int arr[] = {-10,-3,0,5,9};
//    int n = sizeof(arr)/sizeof (arr[0]);
//    ListNode* head = createList(arr,n);
//    inOrder(Solution().sortedListToBST(head));
//}
