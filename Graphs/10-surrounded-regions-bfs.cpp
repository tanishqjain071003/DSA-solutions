#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>>q;

        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && board[i][j] == 'O'){
                    q.push({i,j});
                }
            }
        }
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vis[row][col] = 1;

            for(int i = 0; i<4; i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
                    q.push({nrow,ncol});
                }
            }
        }


        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 0)board[i][j] = 'X';
            }
        }
    }  
};