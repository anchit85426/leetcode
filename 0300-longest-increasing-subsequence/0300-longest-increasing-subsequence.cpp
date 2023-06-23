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
        dp.resize(n+5,vector<int>(n+5,-1));
        return solve(0,nums,-1);
    }
};