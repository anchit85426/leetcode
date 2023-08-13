class Solution {
public:
    int minimizeMax(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int ans=-1;
        sort(nums.begin(),nums.end());
        int high=nums[n-1]-nums[0];
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=1;i<n and cnt<k;i++){
                if(nums[i]-nums[i-1]<=mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};