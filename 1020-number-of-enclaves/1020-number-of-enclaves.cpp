class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
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
          
             if(grid[i][0]==1 ){
                q.push({i,0});
               
            }
            
             if(grid[i][m-1]==1 ){
                q.push({i,m-1});
               
            }
            
            
        }
         for(int i=0;i<m;i++){
          
             if(grid[0][i]==1 ){
                q.push({0,i});
               
            }
            
             if(grid[n-1][i]==1){
                q.push({n-1,i});
               
            }
            
            
        }
        while(!q.empty()){
            int sq=q.size();
            while(sq--){
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                if(grid[x][y]==0){
                    continue;
                }
                count--;
                int dx[4]={0,-1,0,1};
                int dy[4]={1,0,-1,0};
                grid[x][y]=0;
                for(int i=0;i<4;i++){
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx>=0 and newx<n and newy>=0 and newy<m and grid[newx][newy]==1){
                        q.push({newx,newy});
                        
                        
                    }
                }
            }
        }
        return count;
    }
};