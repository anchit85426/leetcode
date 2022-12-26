class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int i=0;
        for(i=0;i<nums.size() and maxi>=i;i++){
            maxi=max(maxi,nums[i]+i);
        }
        
        return i==n;
    }

};