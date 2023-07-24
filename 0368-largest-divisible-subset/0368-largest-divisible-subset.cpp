class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        map<int,int>mpp;
        sort(nums.begin(),nums.end());
        int maxi=1;
        int index=0;
        for(int i=0;i<n;i++){
            mpp[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 and dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    mpp[i]=j;
                    
              }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    index=i;
                }
            }
        }
        vector<int>ans;
        ans.push_back(nums[index]);
        while(mpp[index]!=index){
            index=mpp[index];
            ans.push_back(nums[index]);
            
        }
        return ans;
    }
};