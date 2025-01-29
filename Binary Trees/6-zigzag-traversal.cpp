#include<iostream>
#include<queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        queue<TreeNode*> q;
        
        bool leftToRight = true;

        q.push(root);

        while(!q.empty()){

            int size = q.size();
            vector<int> temp;
            for(int i = 0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                temp.push_back(frontNode->val);

                if(frontNode->left)q.push(frontNode->left);
                if(frontNode->right)q.push(frontNode->right);
            }
            if(leftToRight){
                ans.push_back(temp);
                leftToRight = !leftToRight;
            }
            else{
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                leftToRight = !leftToRight;
            }
        }
        return ans;
    }
};