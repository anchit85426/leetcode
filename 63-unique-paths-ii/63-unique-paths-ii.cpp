class Solution {
    private:
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 and j==0) return dp[0][0];
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }
            }
        }
        if(grid[0][0]==1){
            return 0;
        }
        dp[0][0]=1;
       return  f(n-1,m-1,dp);
    }
};