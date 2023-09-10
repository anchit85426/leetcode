class Solution {
    int solve(int current_idx,vector<vector<int>>&grid,vector<pair<int,int>>&extra,vector<pair<int,int>>&zero){
        if(current_idx==zero.size()){
            return 0;
        }
        int currentx=zero[current_idx].first;
        int currenty=zero[current_idx].second;
        int ans=1e9;
        for(int i=0;i<extra.size();i++){
            int x=extra[i].first;
            int y=extra[i].second;
            if(grid[x][y]>1){
                grid[x][y]-=1;
                grid[currentx][currenty]=1;
                ans=min(ans,abs(x-currentx)+abs(y-currenty)+solve(current_idx+1,grid,extra,zero));
                grid[x][y]+=1;
                grid[currentx][currenty]=0;
            }
        }
        return ans;
    }
public:
    
    int minimumMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>>zero,extra;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    zero.push_back({i,j});
                }
                else if(grid[i][j]>=2){
                    extra.push_back({i,j});
                }
            }
        }
        return solve(0,grid,extra,zero);
    }
};