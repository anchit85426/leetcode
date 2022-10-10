class Solution {
    int f(int ind,vector<int>&coins,int t,vector<vector<int>>&dp){
        if(t==0) return 1;
        if(ind<0)return 0;
        
        
        
        if(dp[ind][t]!=-1) return dp[ind][t];
        int ans=0;
        for(int i=0;i<=t;i+=coins[ind]){
            
            ans+=f(ind-1,coins,t-i,dp);
            
        }
        return dp[ind][t]=ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
      vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
        return f(n-1,coins,amount,dp);
       
        
    }
};