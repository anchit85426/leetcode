class Solution {
    public:
    int f(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]= f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=1+min(f(i,j-1,s1,s2,dp),min(f(i-1,j-1,s1,s2,dp),f(i-1,j,s1,s2,dp)));
        
    }
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
       // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return f(n-1,m-1,s1,s2,dp);
        // for(int i=1;i<=n;i++){
        //     dp[i][0]=i;
        // }
      
        vector<int>prev(m+1,0),curr(m+1,0);
      for(int j=0;j<=m;j++) prev[j]=j;  
        for(int i=1;i<=n;i++){
             curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) curr[j]=prev[j-1];
                else curr[j]=1+min(curr[j-1],min(prev[j-1],prev[j]));
            }
            prev=curr;
        }
        return prev[m];
    }
};