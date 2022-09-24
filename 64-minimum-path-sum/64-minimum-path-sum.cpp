class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dp(m,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) temp[j]=grid[0][0];
                else{
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(i>0) up=grid[i][j]+dp[j];
                    if(j>0) left=grid[i][j]+temp[j-1];
                    temp[j]=min(left,up);
                }
                
            }
            dp=temp;
        }
        return dp[m-1];
    }
};