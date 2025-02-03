#include<iostream>
#include<map>
#include<queue>

using namespace std;

 class Solution{
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(vector<vector<int>>& adj, vector<int>&ans, int node, vector<int>&vis){
        
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto adjNode : adj[node]){
            
            if(vis[adjNode] == 0) 
            solve(adj,ans,adjNode,vis);
        }
        
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int> ans;
        vector<int> vis(V,0);
        
        solve(adj, ans, 0, vis);
        return ans;
    }
};