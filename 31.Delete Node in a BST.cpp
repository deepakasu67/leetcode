#include<iostream>
#include"CreateATreeWithArray.h"
#define null INT_MIN
using namespace std;
class Solution {
public:
    TreeNode* findSuccessor(TreeNode* root, TreeNode*& prev)
    {
        prev = root;
        root = root->right;
        while (root->left != nullptr)
            prev = root,root = root->left;
        return root;
    }

    void deleteALeafNode(TreeNode*& root, TreeNode* prev, TreeNode* temp)
    {
        if (temp->left == nullptr && temp->right == nullptr) //leaf node to be delted
        {
            if (prev == nullptr) //only one node to be deleted;
                delete temp, root = nullptr;
            else
            {
                if (prev->left == temp)
                    prev->left = nullptr;
                else
                    prev->right = nullptr;
                delete temp;
            }
        }        
    }

    void deleteANodeWithOneSubtree(TreeNode*& root, TreeNode* prev, TreeNode* temp)
    {
        if (temp->left != nullptr || temp->right != nullptr) //one subtree
        {
            if (prev == nullptr) // node to be deleted is root
            {
                if (temp->left != nullptr)
                    root = root->left;
                else
                    root = root->right;
            }
            else if (temp->left != nullptr) //check where temp is there
            {
                if(prev->left == temp) // we need to check where we need to attach hanging subtree i.e left or right subtree of prev
                    prev->left = temp->left;
                else
                    prev->right = temp->left;
            }
            else
            {
                if (prev->left == temp)
                    prev->left = temp->right;
                else
                    prev->right = temp->right;
            }
            delete temp;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        TreeNode* temp = root;
        TreeNode* prev = nullptr;
        while (temp != nullptr)
        {
            if (key < temp->val)
            {
                prev = temp;
                temp = temp->left;
            }
            else if (key > temp->val)
            {
                prev = temp;
                temp = temp->right;
            }
            else
            {
                if (temp->left == nullptr && temp->right == nullptr) //leaf node to be delted
                {
                    deleteALeafNode(root, prev, temp);;
                }
                else if (temp->left == nullptr || temp->right == nullptr) //one subtree
                {
                    deleteANodeWithOneSubtree(root, prev, temp);
                }
                else// two subtree 
                {
                    TreeNode* successor = findSuccessor(temp,prev);
                    temp->val = successor->val;
                    if (successor->left == nullptr && successor->right == nullptr)
                        deleteALeafNode(root, prev, successor);
                    else
                        deleteANodeWithOneSubtree(root, prev, successor);
                }

                return root;
            }
        }
        return root;
    }
};
//int main(void)
//{
//    int a[] = { 5,2,6,null,4,null,7 };
//    int n = sizeof(a) / sizeof(a[0]);
//    Solution obj;
//    TreeNode* node = build_tree(a, n);
//    obj.deleteNode(node,2);
//    inOrder(node);
//}