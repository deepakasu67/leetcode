#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;

class Solution {
public:
	Solution()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
	void kthSmallestUtil(TreeNode* root, int &k, TreeNode *&foundNode)
	{
		if (root == nullptr)
			return ;
		kthSmallestUtil(root->left, k, foundNode);
		k--;
		if (k == 0)
			foundNode = root;
		kthSmallestUtil(root->right, k, foundNode);
	}
	int kthSmallest(TreeNode* root, int k) {
		TreeNode* result = nullptr;
		kthSmallestUtil(root, k, result);
		return result->val;
	}
};


//int main(void)
//{
//	int arr[] = { 3,1,4,INT_MIN,2 };
//	TreeNode* root = build_tree(arr, 5);
//	inOrder(root);
//	Solution obj;
//
//	cout << obj.kthSmallest(root, 1);
//}