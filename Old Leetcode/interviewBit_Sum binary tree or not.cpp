#include<iostream>
#include"CreateATreeWithArray.h"
using namespace std;
int solveutil(TreeNode* root, bool *ans)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return root->val;
	int lsplusRs = solveutil(root->left,ans) + solveutil(root->right, ans);
	if (root->val != lsplusRs)
		*ans = false;
	return lsplusRs + root->val;
}
int solve(TreeNode* A) 
{
	bool ans = true;
	solveutil(A, &ans);
	return ans;
}
//int main(void)
//{
//	int a[] = {3};
//	TreeNode* root = build_tree(a,1);
//	inOrder(root);
//	cout <<endl<< solve(nullptr);
//}
