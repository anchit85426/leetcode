class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int n=nums.size();
        int prefix=0;
        int ans=0;
        for(auto it:nums){
            prefix+=it;
            int target=prefix-k;
            
            if(mpp.count(target)){
                ans+=mpp[target];
            }
            mpp[prefix]++;
        }
        return ans;
    }
};