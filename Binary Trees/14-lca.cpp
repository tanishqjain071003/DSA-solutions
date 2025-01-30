#include<iostream>
using namespace std;

struct TreeNode {
     TreeNode *left;
     TreeNode *right;
     int val;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL || root == p || root == q)return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(right == NULL)return left;
        else if(left == NULL)return right;
        else return root;

    }
};