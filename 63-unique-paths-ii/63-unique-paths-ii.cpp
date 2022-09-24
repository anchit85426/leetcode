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
        int dp[n][m];
        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=m-1;j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }
                else if(i==0 && j==0 ) dp[i][j]=1;
                else{
                    int up=0,left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};