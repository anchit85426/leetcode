class Solution {
    public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
         int n=nums.size();
        vector<int>pre;
        pre.push_back(0);
        pre.push_back(1);
        int  ans=0;
         int mod=1e9+7;
        for(int i=2;i<=n;i++){
            pre.push_back((pre.back()<<1)%mod);
        }
        
       int j=n-1;
        for(int i=0;i<n and i<=j;i++){
            if(nums[i]>target){
                continue;
            }
          
            while(i<=j and nums[i]+nums[j]>target){
               j--;
            }
            ans=(ans+pre[j-i+1])%mod;
         
        }
        
        return ans;
    }
};