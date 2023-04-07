//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,vector<pair<int,int>>&v,int row0,int col0){
        vis[row][col]=1;
        v.push_back({row-row0,col-col0});
          int n=grid.size();
        int m=grid[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newx=dx[i]+row;
            int newy=dy[i]+col;
            if(newx>=0 and newx<n and newy>=0 and newy<m and !vis[newx][newy] and grid[newx][newy]==1){
                dfs(newx,newy,vis,grid,v,row0,col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    vector<pair<int,int>>v;
                    dfs(i,j,vis,grid,v,i,j);
                    s.insert(v);
                    
                } 
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends