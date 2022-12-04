class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m=n;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        int dx[8]={-1,0,1,0,-1,-1,1,1};
        int dy[8]={0,1,0,-1,-1,1,-1,1};
        pair<int,int>source={0,0};
        pair<int,int>destination={n-1,n-1};
        if(grid[0][0]==1){
            return -1;
        }
        dist[source.first][source.second]=0;
        q.push({1,{source.first,source.second}});
        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==destination.first and y==destination.second){
                return dis;
            }
            q.pop();
            for(int i=0;i<8;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0 and newX<=n-1 and newY>=0 and newY<=m-1 and grid[newX][newY]==0){
                    
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