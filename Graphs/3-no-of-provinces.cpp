#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solve(vector<int> adj[], vector<int> &vis, int node){
        vis[node] = 1;

        for(auto adjNode : adj[node]){
            if(vis[adjNode] == 0){
                solve(adj,vis,adjNode);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();

        vector<int> adj[V+1];

        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        int count = 0;
        for(int i = 0; i<V; i++){
            if(vis[i] == 0){
                count++;
                solve(adj, vis, i);
            }
        }

        return count;
    }
};