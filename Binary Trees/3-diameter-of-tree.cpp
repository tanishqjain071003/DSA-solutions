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
    int height(TreeNode* root){
        if(root == NULL)return 0;

        return 1+max(height(root->left), height(root->right));
    }
    int solve(TreeNode* root, int &ans){

        if(root == NULL)return 0;

        int leftHeight = solve(root->left,ans);
        int rightHeight = solve(root->right,ans);

        ans = max(ans, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);

    }
    int diameterOfBinaryTree(TreeNode* root) {

        // brute force
        // if(root == NULL)return 0;

        // int leftHeight = height(root->left);
        // int rightHeight = height(root->right);

        // return max(max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)),leftHeight + rightHeight);

        //optimised

        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};