#include<iostream>
#include<queue>
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
    int lHeight(TreeNode* root){
        int count = 0;
        TreeNode* temp = root;
        while(temp){
            temp = temp->left;
            count++;
        }
        return count;
    }
    int rHeight(TreeNode* root){
        int count = 0;
        TreeNode* temp = root;
        while(temp){
            temp = temp->right;
            count++;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;
        int leftHeight = lHeight(root);
        int rightHeight = rHeight(root);

        if(leftHeight == rightHeight)return (1<<leftHeight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};