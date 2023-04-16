class Solution {
    int dp[1001][2001];

    private:
    int find(int idx,vector<vector<int>>&piles,int k){
        if(idx<0 or k<=0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int total=find(idx-1,piles,k);
        int sum=0;
        int j=piles[idx].size();
        for(int i=0;i<min(k,j);i++){
            sum+=piles[idx][i];
            total=max(total,sum+find(idx-1,piles,k-(i+1)));
        }
        return dp[idx][k]=total;
    }
    public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        find(n-1,piles,k);
        return dp[n-1][k];
    }
};