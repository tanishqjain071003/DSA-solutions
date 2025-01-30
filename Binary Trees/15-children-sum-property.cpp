#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(!root)return 1;
     if(!root->left && !root->right)return 1;
     
     int left = 0,right = 0;
     if(root->left)left = root->left->data;
     if(root->right)right = root->right->data;
     
     int sum = left + right;
     
     if(sum == root->data)return isSumProperty(root->left)&&isSumProperty(root->right);
     
     return 0;
     
    }
};