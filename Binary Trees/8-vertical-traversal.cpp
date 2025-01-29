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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return {};

        vector<vector<int>>ans;
        vector<pair<pair<int,int>,int>>temp;

        queue <pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){

            auto front = q.front();
            q.pop();
            int horizontal = front.second.second;
            int vertical = front.second.first;
            TreeNode* node = front.first;

            temp.push_back({{vertical,horizontal},node->val});

            if(node->left)q.push({node->left,{vertical-1,horizontal+1}});
            if(node->right)q.push({node->right,{vertical+1,horizontal+1}});
        }
        sort(temp.begin(), temp.end());
        map<int, vector<int>> mp;

        for (auto p : temp) {
            int verticalLevel = p.first.first;
            int nodeValue = p.second;
            mp[verticalLevel].push_back(nodeValue);
        }
        for (auto p : mp) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};