class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        queue<pair<int,int>>q;
        int count=0;
        for(auto it :grid){
            for(auto it2 :it){
                if(it2==1){
                    count++;
                }
            }
        }
        for(int i=0;i<n;i++){
          
             if(grid[i][0]==1 and vis[i][0]==0){
                q.push({i,0});
                vis[i][0]=1;
            }
            
             if(grid[i][m-1]==1 and vis[i][m-1]==0){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
            
            
        }
         for(int i=0;i<m;i++){
          
             if(grid[0][i]==1 and vis[0][i]==0){
                q.push({0,i});
                vis[0][i]=1;
            }
            
             if(grid[n-1][i]==1 and vis[n-1][i]==0){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
            
            
        }
        while(!q.empty()){
            int sq=q.size();
            while(sq--){
                int x=q.front().first;
                int y=q.front().second;
                count--;
                q.pop();
                int dx[4]={0,-1,0,1};
                int dy[4]={1,0,-1,0};
                for(int i=0;i<4;i++){
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx>=0 and newx<n and newy>=0 and newy<m and !vis[newx][newy] and grid[newx][newy]==1){
                        q.push({newx,newy});
                        vis[newx][newy]=1;
                    }
                }
            }
        }
        return count;
    }
};