class Solution {
    int dp[15][32768];
    int ans=0;
    int f(int op,long long int mask,vector<int>&nums){
        int n=nums.size();
        if(op>(nums.size()/2)){
            return 0;
        }
       
        if(dp[op][mask]!=-1){
            return dp[op][mask];
        }
        for(int i=0;i<n;i++){
            if((mask>>i)&1){ 
                continue;
            }
            for(int j=i+1;j<n;j++){
                if((mask>>j)&1) {continue;
                                }
                int nmask=mask|(1<<i)|(1<<j);
                dp[op][mask]=max(dp[op][mask],op*__gcd(nums[i],nums[j])+f(op+1,nmask,nums));
                
            }
            
        }
        return dp[op][mask];
    }
public:
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
      return   f(1,0,nums);
       
    }
};