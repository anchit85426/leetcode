class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();   
        vector<vector<int>>vis(n,vector<int>(m,0));
        auto check=[](int nrow,int ncol,int n,int m){
            return nrow>=0 and nrow<n and ncol>=0 and ncol<m ;
        };
        int ans=1e7;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    queue<pair<pair<int,int>,int>>q;
                    queue<pair<pair<int,int>,int>>q2;
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    while(!q.empty()){
                        int x=q.front().first.first;
                        int y=q.front().first.second;
                        int dist=q.front().second;
                        q.pop();
                        q2.push({{x,y},0});
                        int dx[]={-1,0,1,0};
                        int dy[]={0,-1,0,1};
                        for(int i=0;i<4;i++){
                            int nrow=dx[i]+x;
                            int ncol=dy[i]+y;
                            if(check(nrow,ncol,n,m)){
                               if(!vis[nrow][ncol] and grid[nrow][ncol]==1){
                                   
                                   vis[nrow][ncol]=1;
                                   
                                       q.push({{nrow,ncol},0});
                                  }
                            
                        }
                      }
                    }
                    
                   
                    while(!q2.empty()){
                        int x=q2.front().first.first;
                        int y=q2.front().first.second;
                        int dist=q2.front().second;
                        q2.pop();
                        int dx[]={-1,0,1,0};
                        int dy[]={0,-1,0,1};
                        for(int i=0;i<4;i++){
                            int nrow=dx[i]+x;
                            int ncol=dy[i]+y;
                            if(check(nrow,ncol,n,m)){
                              if(!vis[nrow][ncol] and grid[nrow][ncol]==0){
                                  q2.push({{nrow,ncol},dist+1});
                                  vis[nrow][ncol]=1;
                              }
                                else if(!vis[nrow][ncol] and grid[nrow][ncol]==1){
                                   return dist;
                                    vis[nrow][ncol]=1;
                                }
                            
                        }
                      }
                    }
                    
                    return ans;
                    
                }
            }
        }
        return ans;
    }
};