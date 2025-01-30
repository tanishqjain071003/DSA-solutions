#include<iostream>
#include<queue>
#include<map>
#include<stack>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:   
    void solve(Node* root,vector<int>&temp ,vector<vector<int>>&ans){
        
        if(!root)return;
        if(!root->left && !root->right){
            temp.push_back(root->data);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->data);
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int> temp;
        solve(root, temp, ans);
        
        return ans;
    }
};