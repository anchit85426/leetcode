class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans=0;
        int n=nums.size();
        int cnt=0;
        while(j<n){
            if(nums[j++]%2==1) cnt++;
            if(cnt>k) {
                i++; cnt--;
            }
            if(cnt==k){
                int left=0,right=0;
                while(j<n and (nums[j]%2==0)){
                    left++;
                    j++;
                }
                while(i<n and (nums[i]%2==0)){
                    right++;
                    i++;
                }
                ans=ans+((left+1)*(right+1));
            }
        }
        return ans;
    }
};