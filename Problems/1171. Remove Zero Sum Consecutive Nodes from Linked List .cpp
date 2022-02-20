//
// Created by Deepak Sahu on 12/31/21.
//
#include <iostream>
#include<unordered_map>
#include <vector>
#include "LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* createList(vector<int>& arr)
    {
        int n=arr.size();
        ListNode* head = NULL;
        ListNode* p = new ListNode();

        int i;
        for (i = 0; i < n; ++i)
        {
            if(arr[i] == INT_MIN)
                continue;
            if (head == NULL)
                head = p;
            else
            {
                p->next = new ListNode();
                p = p->next;
            }
            p->val = arr[i];
            p->next = NULL;
        }
        return head;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> nums;
        ListNode* head_1 = head;
        while(head_1)
        {
            nums.push_back(head_1->val);
            head_1 = head_1->next;
        }
        unordered_map<int, int> prefixSum;
        int sum =0;
        prefixSum[sum] = -1;
        for(int i =0;i < nums.size(); i++)
        {
            sum += nums[i];

            if(prefixSum.count(sum))
            {
                int stIdx = prefixSum[sum]+1;
                int ac = sum;
                while(stIdx <= i)
                {
                    if(nums[stIdx] == INT_MIN)
                    {
                        stIdx++;
                        continue;
                    }
                    ac+=nums[stIdx];
                    prefixSum.erase(ac);
                    nums[stIdx] = INT_MIN;
                    stIdx++;
                }
            }
            prefixSum[sum] = i;
        }

        return createList(nums);
    }
};

//int main(void)
//{
//    int arr[] = {1,2,3,-3,-2};
//    int n  = sizeof (arr)/sizeof (arr[0]);
//    ListNode* head = createList(arr, n);
//    printList(Solution().removeZeroSumSublists(head));
//}
