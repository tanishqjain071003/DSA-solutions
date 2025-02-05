#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};

        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans[i][j] = mat[i][j];
            }
        }

        queue<pair<pair<int,int>,int>>q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
               if(mat[i][j] == 0){
                vis[i][j] = 1;    
                q.push({{i,j},0});
               }
            }
        }

        while(!q.empty()){

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            ans[row][col] = dist;

            for(int i = 0; i<4; i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];

                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m &&vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return ans;
    }
};