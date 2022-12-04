//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int  n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==destination.first and y==destination.second){
                return dis;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0 and newX<=n-1 and newY>=0 and newY<=m-1 and grid[newX][newY]==1){
                    if(dis+1<dist[newX][newY]){
                        dist[newX][newY]=dis+1;
                        q.push({dist[newX][newY],{newX,newY}});
                        if(newX==destination.first and newY==destination.second){
                            return dis+1;
                        }
                    }
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends