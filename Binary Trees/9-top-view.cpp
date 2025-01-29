#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        queue<pair<int,Node*>>q;
        map<int,int>mp;
        q.push({0,root});
        
        while(!q.empty()){
            Node* node = q.front().second;
            int level = q.front().first;
            q.pop();
            if(mp.find(level) == mp.end())mp[level] = node->data;
            
            if(node->left)q.push({level-1,node->left});
            if(node->right)q.push({level+1,node->right});
        }
    
        for(auto m:mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};