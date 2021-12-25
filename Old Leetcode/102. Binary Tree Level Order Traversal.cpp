#include"CreateATreeWithArray.h"
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    void levelOrderUtil(TreeNode* root,int level, vector<vector<int>> &levelOrderNodes)
    {
        if (!root)
            return;
        if (levelOrderNodes.size() == level)
            levelOrderNodes.push_back(vector<int>());

        levelOrderNodes[level].push_back(root->val);
        levelOrderUtil(root->left, level + 1, levelOrderNodes);
        levelOrderUtil(root->right, level + 1, levelOrderNodes);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderUtil(root, 0, result);
        return result;
    }
};
//int main(void)
//{
//    int arr[] = { 3,9,20,INT_MIN,INT_MIN,15,7 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    TreeNode* root1 = nullptr;
//    TreeNode* root = insertLevelOrder(arr, root1, 0, n);
//    inOrder(root);
//    Solution obj;
//    obj.levelOrder(root);
//}