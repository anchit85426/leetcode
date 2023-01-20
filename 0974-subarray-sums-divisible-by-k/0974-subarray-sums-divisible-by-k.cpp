class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int ans=0;
        int prefix=0;
        for(auto it :nums){
            prefix+=it%k+k;
            if(mpp[(prefix)%k]){
                ans+=mpp[(prefix)%k];
            }
            mpp[(prefix)%k]++;
        }
        return ans;
    }
};