class Solution {
    vector<vector<int>>dp;
    int solve(int ind,vector<int>&nums,int prev){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int len=solve(ind+1,nums,prev);
        if (prev==-1 or nums[ind]>nums[prev] ){
            len=max(len,1+solve(ind+1,nums,ind));
        }
        return dp[ind][prev+1]=len;
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+5,vector<int>(n+5,0));
        // return solve(0,nums,-1);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int len=dp[ind+1][prev+1];
                if(prev==-1 or nums[prev]<nums[ind]){
                    len=max(len,1+dp[ind+1][ind+1]);
                }
                dp[ind][prev+1]=len;
            }
        }
        return dp[0][0];
    }
};