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

    int solve(TreeNode* root){

        if(root == NULL)return 0;

        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);

        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight-rightHeight) > 1)return -1;

        return max(leftHeight, rightHeight)+1;

    }

    bool isBalanced(TreeNode* root) {
        // Brute Force
        // if(root == NULL)return true;

        // int leftHeight = height(root->left);
        // int rightHeight = height(root->right);

        // if(abs(leftHeight - rightHeight) > 1)return false;

        // return isBalanced(root->left) && isBalanced(root->right);

        // Optimised

        int height = solve(root);

        if(height == -1)return false;
        return true;
    
    }
};
