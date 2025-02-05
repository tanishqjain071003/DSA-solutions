#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    public:
        // Function to detect cycle in an undirected graph.
        bool solve(vector<vector<int>>& adj, int node){
            int V = adj.size();
            vector<int> vis(V,0);
            
            queue<pair<int,int>>q;
            
            q.push({node,-1});
            vis[node] = 1;
            
            
            while(!q.empty()){
                
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                
                vis[node] = 1;
                
                for(auto adjNode : adj[node]){
                    
                    if(vis[adjNode] == 0){
                        q.push({adjNode, node});
                    }
                    else if(adjNode != parent){
                        return true;
                    }
                }
            }
            return false;
        }
        bool isCycle(vector<vector<int>>& adj) {
            // Code here
            int V = adj.size();
        for(int i = 0; i<V; i++){
            if(solve(adj,i) == true)return true;
        }
        return false;
        }
};