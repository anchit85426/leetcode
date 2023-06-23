class Solution {
    vector<vector<int>>dp;
    int solve(int prevIndex,int mask,int n){
        if(prevIndex==n+1) return 1;
        if(dp[prevIndex][mask]!=-1) return dp[prevIndex][mask];
        int total=0;
        for(int j=1;j<=n;j++){
            if(((mask>>j)&1)==0){
            if(prevIndex==1 or prevIndex%j==0 or j%prevIndex==0){
                total+=solve(prevIndex+1,mask|(1<<j),n);
                
            }
         }
        }
        return dp[prevIndex][mask]=total;
    }
public:
    int countArrangement(int n) {
        dp.resize(17,vector<int>((1<<15+5),-1));
        return solve(1,0,n);
    }
};