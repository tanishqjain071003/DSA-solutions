#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        

        int m = image.size();
        int n = image[0].size();

        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,-1,0,1};

        int srccolor = image[sr][sc];
        if(color == srccolor)return image;
        
        queue<pair<int,int>>q;
        q.push({sr,sc});

        image[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                for(int j = 0; j<4; j++){
                    int nrow = row + dRow[i];
                    int ncol = col + dCol[i];
                    
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == srccolor){
                        q.push({nrow,ncol});
                        image[nrow][ncol] = color;
                    }
                }
            }

        }

        return image;
    }
};