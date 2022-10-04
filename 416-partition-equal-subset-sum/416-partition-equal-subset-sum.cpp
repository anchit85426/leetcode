class Solution {
    private:
        bool SubsetSum(int idx,vector<int>&nums,int target,vector<vector<int>>&dp){
            if(idx==0) return nums[0]==target;
            if(target==0) return true;
            if(dp[idx][target]!=-1) return dp[idx][target];
            bool nottake=SubsetSum(idx-1,nums,target,dp);
            bool take=false;
            if(target>=nums[idx]) take=SubsetSum(idx-1,nums,target-nums[idx],dp);
            return dp[idx][target]=take||nottake;
        }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it :nums){
            sum+=it;
        }
        if(sum%2==1){
            return false;
        }
        int target=sum/2;
        vector<vector<int>>dp(201,vector<int>(20000,-1));
        return SubsetSum(nums.size()-1,nums,target,dp);
    }
};