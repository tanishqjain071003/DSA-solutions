#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int solve(TreeNode* root, int &ans){
        if(root == NULL)return 0;

        int value = root->val;

        int leftMPS = max(0,solve(root->left,ans));
        int rightMPS = max(0,solve(root->right,ans));

        int treatingRootAsCenter = value + leftMPS + rightMPS;
        ans = max(ans, treatingRootAsCenter);
        return value + max(leftMPS, rightMPS);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};