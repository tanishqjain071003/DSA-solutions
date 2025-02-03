#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*> q;
        q.push(root);

        string s = "";

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                s = s + "#,";
                continue;
            }

            s = s + to_string(front->val) + ",";

            if(front->left)q.push(front->left);
            else q.push(NULL);
            if(front->right)q.push(front->right);  
            else q.push(NULL); 
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* front = q.front();
            q.pop();

            getline(s,str,',');

            if(str != "#"){
                front->left = new TreeNode(stoi(str));
                q.push(front->left);
            }
            getline(s,str,',');
            if(str != "#"){
                front->right = new TreeNode(stoi(str));
                q.push(front->right);
            }
        }
        return root;
    }
};
