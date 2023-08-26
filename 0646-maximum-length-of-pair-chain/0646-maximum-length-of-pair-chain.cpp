class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[1]!=b[1]){
            return a[1]<b[1];
        }
        else return a[0]<b[0];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),comp);
        int ans=1;
        int cnt=1;
        int n=pairs.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                ans=max(ans,dp[i]);
                
            }
        }
        return ans;
    }
};