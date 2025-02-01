#include<iostream>
#include<map>

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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, map<int,int>&mp){

        if(postorderStart > postorderEnd || inorderStart > inorderEnd)return NULL;

        TreeNode* root = new TreeNode(postorder[postorderEnd]);
        int point = mp[postorder[postorderEnd]];
        int rightTreeLength = inorderEnd - point;

        root->left = solve(inorder, postorder, inorderStart, point - 1, postorderStart,postorderEnd-rightTreeLength - 1,mp);
        root->right = solve(inorder, postorder, point+1, inorderEnd, postorderEnd - rightTreeLength, postorderEnd - 1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderStart = 0;
        int postorderEnd = postorder.size() - 1;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;

        map<int,int>mp;
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(inorder, postorder, inorderStart, inorderEnd, postorderStart, postorderEnd, mp);

    }
};