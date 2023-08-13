class Solution {
    vector<int>dp;
    bool solve(int i,vector<int>&nums,int n){
        if(i==n) return true;
        if(dp[i]!=-1){
            return dp[i];
        }
        if(i+1<n and nums[i]==nums[i+1] ){
            if(solve(i+2,nums,n)) return true;
            if(i+2<n and nums[i]==nums[i+2]){
                if(solve(i+3,nums,n)) return true;
            }
        }
        if(i+2<n and nums[i]+1==nums[i+1] and nums[i]+2==nums[i+2]){
            if(solve(i+3,nums,n)) return true;
        }
        return dp[i]= false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return solve(0,nums,n);
    }
};