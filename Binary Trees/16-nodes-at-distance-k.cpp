#include<iostream>
#include<queue>
#include<map>

using namespace std;

struct TreeNode {
     TreeNode *left;
     TreeNode *right;
     int val;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        vector<int> ans;
        queue<TreeNode*> q;
        mp[root] = NULL;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->left){
                mp[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right){
                mp[front->right] = front;
                q.push(front->right);
            }     
        }
        queue<pair<TreeNode*, int>>q1;

        q1.push({target,0});
        map<TreeNode*,bool>vis;
 
        while(!q1.empty()){
            
            int size = q1.size();
            for(int i = 0;  i<size; i++){
                TreeNode* front = q1.front().first;
                int level = q1.front().second;
                vis[front] = true;
                q1.pop();

                if(level == k)ans.push_back(front->val);
                if(level > k)continue;

                if(front->left && !vis[front->left]){
                    q1.push({front->left,level+1});
                }
                if(front->right && !vis[front->right]){
                    q1.push({front->right,level+1});
                }
                if(mp[front] && !vis[mp[front]]){
                    q1.push({mp[front],level+1});
                }
            }
        }

        return ans;


    }
};