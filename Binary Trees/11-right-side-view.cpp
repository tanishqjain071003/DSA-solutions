#include<iostream>
#include<queue>
#include<map>
#include<stack>

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
    void solve(TreeNode* root, stack<int> &s, int level){
        if(root == NULL)return;

        if(s.size() == level)s.push(root->val);

        solve(root->right,s,level+1);
        solve(root->left,s,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        stack<int> s;
        solve(root,s,0);

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};