//
// Created by Deepak Sahu on 1/2/22.
//
#include <iostream>
#include <string>
#include "CreateATreeWithArray.h"
using namespace  std;

class Solution {
    string lexicographicallySmaller;
public:
    void smallestFromLeafHelper(TreeNode* root, string &str)
    {
        if(root == nullptr)
            return;
        str += (root->val +'a');
        if(root->left == nullptr && root->right == nullptr)
        {
            string strTillNow(str.rbegin(),str.rend());
            if(lexicographicallySmaller.empty())
            {
                lexicographicallySmaller = strTillNow;
            }
            else
            {
                if(!std::lexicographical_compare(lexicographicallySmaller.begin(), lexicographicallySmaller.end(), strTillNow.begin(),strTillNow.end()))
                {
                    lexicographicallySmaller = strTillNow;
                }
            }
            str.pop_back();
            return;
        }

        smallestFromLeafHelper(root->left,str);
        smallestFromLeafHelper(root->right, str);
        str.pop_back();
    }
    string smallestFromLeaf(TreeNode* root)
    {
        string s;
        smallestFromLeafHelper(root,s);
        return lexicographicallySmaller;
    }
};

//int main(void)
//{
//    //int arr[] = {0,1,2,3,4,3,4};
//    //int arr[] = {25,1,3,1,3,0,2};
//    int arr[] = {4,0,1,1};
//    int n = sizeof (arr)/sizeof (arr[0]);
//    TreeNode* root = build_tree(arr, n);
//    cout<<Solution().smallestFromLeaf(root);
//}
