class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        mpp[0]=-1;
        int prefix=0;
        for(int i=0;i<n;i++){
            prefix=(prefix+nums[i]%k)%k;
            int target=(prefix-k+k)%k;
           
            if(mpp.count(target)){
                
                if(i-mpp[target]>=2){
                    return true;
                }
            }
            if(mpp.find(prefix)==mpp.end()){
                mpp[prefix]=i;
            }
        }
        return false;
    }
};