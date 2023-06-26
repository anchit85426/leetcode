class Solution {
    int mod=1e9+7;
    vector<vector<int>>dp;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int solve(int i,int j,vector<vector<int>>&grid){
        if(dp[i][j]!=-1) return dp[i][j];
        long long int res=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int nrow=i+dx[k],ncol=j+dy[k];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]>grid[i][j]){
                res=(res+solve(nrow,ncol,grid))%mod;
            }
        }       
        return dp[i][j]=res;
    }
    
public:
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        long long int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+solve(i,j,grid))%mod;
            }
        }
        return ans;
    }
};