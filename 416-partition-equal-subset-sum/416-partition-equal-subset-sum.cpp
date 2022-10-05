class Solution {
    private:
        bool SubsetSum2(int idx,vector<int>&nums,int target){
            vector<bool>prev(target+1,false),curr(target+1,false);
            prev[0]=curr[0]=true;
            if(nums[0]<=target)prev[nums[0]]=true;
            for(int i=1;i<idx;i++){
                for(int k=1;k<=target;k++){
                    bool nottake=prev[k];
                    bool take=false;
                    if(nums[i]<=k) take=prev[k-nums[i]];
                    curr[k]=take|nottake;
                }
                prev=curr;
            }
            return  prev[target];
        }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        if(nums.size()==1) return false;
        for(auto it :nums){
            sum+=it;
        }
        if(sum%2==1){
            return false;
        }
        int target=sum/2;

        return SubsetSum2(nums.size(),nums,target);
    }
};