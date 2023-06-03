class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        long long int  low=1;
        long long int high=1e9;
        sort(nums.begin(),nums.end(),greater<int>());
        auto possible=[&](int mid){
            long long int  operations=0;
            for(int i=0;i<n;i++){
                operations+=((nums[i]+mid-1)/mid)-1;
    
            }
            return operations<=maxOperations;
        };
        int ans=-1;
       
        while(low<=high){
            // mid is the max no of balls
            long long int  mid=low+(high-low)/2;
            // cout<<mid<<endl;
            if(possible(mid)){
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