class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        vector<int>dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] and dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] and dp[i]==dp[j]+1){
                    cnt[i]+=cnt[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        int i=0;
        for(auto it:dp){
            if(it==maxi){
                ans+=cnt[i];
            }
            i++;
        }
        return ans;
    }
};