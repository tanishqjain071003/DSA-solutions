#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};

        vector<vector<int>> vis(m, vector<int>(n,0));
        int ans = 0;

        queue<pair<pair<int,int>,int>> q;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
               
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            for(int i = 0 ; i<4; i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];

                if(nrow < m && nrow >=0 && ncol < n && ncol >=0 && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow,ncol},time + 1});
                }
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1)return -1;
            }
        }

        return ans;
    }
};