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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int inorderStart, int inorderEnd, int preorderStart, int preorderEnd, map<int,int>& mp){

        if(inorderStart > inorderEnd || preorderStart > preorderEnd)return NULL;

        TreeNode* root = new TreeNode(preorder[preorderStart]);

        int number = mp[preorder[preorderStart]];
        int leftTreeSize = number - inorderStart;

        root->left = solve(preorder, inorder, inorderStart,number-1,preorderStart+1,preorderStart + leftTreeSize,mp);
        root->right = solve(preorder, inorder, number + 1,inorderEnd,preorderStart+leftTreeSize+1,preorderEnd,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int preorderStart = 0;
        int preorderEnd = preorder.size() - 1;

        map<int, int> mp;
        for(int i = 0 ; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, inorderStart, inorderEnd, preorderStart, preorderEnd, mp);

    }
};