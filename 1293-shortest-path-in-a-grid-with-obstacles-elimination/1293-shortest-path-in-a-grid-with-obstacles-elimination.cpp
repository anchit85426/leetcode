class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
       int m=grid[0].size();
    vector<vector<vector<bool>>>v(n+1, vector<vector<bool>>(m+1,vector<bool>(k+4)));
     queue<vector<int>>q;
        int steps=0;
        q.push({0,0,k});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int s=q.size();
            while(s-->0){
                vector<int>curr=q.front();
                q.pop();
                
                int row=curr[0],col=curr[1], left=curr[2];
                if(row==n-1 and col==m-1) return steps;
                for(int i=0;i<4;i++){
                    int nrow=dx[i]+row;
                    int ncol=dy[i]+col;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and left-grid[nrow][ncol]>=0 and v[nrow][ncol][left-grid[nrow][ncol]]==false ){
                        q.push({nrow,ncol,left-grid[nrow][ncol]});
                        v[nrow][ncol][left-grid[nrow][ncol]]=true;
                    }
                    
                }
                
            }
            steps++;
        }
        return -1;
    }
};