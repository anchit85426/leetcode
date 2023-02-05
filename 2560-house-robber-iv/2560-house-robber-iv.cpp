class Solution {
    private: 
    int isPossible(vector<int>nums,int k,int mid){
        int n=nums.size();
        int lastIndex=-10;
        int canSteel=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mid){
                continue;
            }
            if(lastIndex+1==i){
                continue;
            }
            canSteel++;
            lastIndex=i;
        }
        return canSteel>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=1e9+1;
        int ans=-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(isPossible(nums,k,mid)){
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