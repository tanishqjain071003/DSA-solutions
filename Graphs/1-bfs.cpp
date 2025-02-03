#include<iostream>
#include<map>
#include<queue>

using namespace std;

 class Solution{
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int V = adj.size();
        vector<int> ans;
        vector<int>vis(V,0);
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto adjNode : adj[node]){
                if(vis[adjNode] == 0){
                    q.push(adjNode);
                    vis[adjNode] = 1;
                   
                }
            }
        }
        return ans;
        
    }
};