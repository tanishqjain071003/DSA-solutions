#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    public:
        // Function to detect cycle in an undirected graph.
        bool dfs(vector<vector<int>>& adj, int node, int parent, vector<int>&vis){
            vis[node] = 1;
            
            for(auto adjNode:adj[node]){
                if(vis[adjNode] == 0){
                    if(dfs(adj, adjNode, node, vis) == true)
                    return true;
                }
                else if(parent != adjNode)return true;
            }
            return false;
        }
    
        bool isCycle(vector<vector<int>>& adj) {
        // Code here
            int V = adj.size();
            vector<int> vis(V,0);
            for(int i = 0; i<V; i++){
                if(vis[i] == 0 && dfs(adj, i, -1, vis) == true)return true;
            }
            return false;
        }
};