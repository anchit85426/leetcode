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
    int lengthOfLIS(vector<int>& arr) {
       vector<int>dp(arr.size()+1,1);
        int n=arr.size();
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] and dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};