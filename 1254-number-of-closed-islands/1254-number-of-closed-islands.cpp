class Solution {
    private:
    int fill(int x,int y,vector<vector<int>>&grid){
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y]){
            return 0;
        }
        return (grid[x][y]=1)+ fill(x-1,y,grid)+fill(x,y-1,grid)+fill(x+1,y,grid)+fill(x,y+1,grid);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0 or i==n-1 or j==m-1 ){
                    if(grid[i][j]==0){
                        fill(i,j,grid);
                    }
                }
            }
        }
        long long res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    res++;
                    fill(i,j,grid);
                }
            }
        }
     return res;   
    }
};