#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(root);
        Node* targetNode = NULL;
        
        while(!q.empty()){
                
            Node* front = q.front();
            q.pop();
            
            if(front->data == target)targetNode = front;
            
            if(front->left){
                mp[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right] = front;
                q.push(front->right);
            }
        }
        
        queue<pair<Node*,int>>q1;
        q1.push({targetNode, 0});
        map<Node*,bool>vis;
        
        int ans = 0;
        
        while(!q1.empty()){
            
            Node* front = q1.front().first;
            int level = q1.front().second;
            q1.pop();
            vis[front] = true;
            
            if(front->left && !vis[front->left])q1.push({front->left,level+1});
            if(front->right && !vis[front->right])q1.push({front->right,level+1});
            if(mp[front] && !vis[mp[front]])q1.push({mp[front],level+1});
            
            
            ans = max(ans, level);
        }
        
        return ans;
    }
};