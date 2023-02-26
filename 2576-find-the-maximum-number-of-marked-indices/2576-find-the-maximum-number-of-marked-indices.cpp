class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        
        int i=0;
       
        int n=nums.size();
         int j=n/2;
        if(n==1){
            return 0;
        }
        int ans=0;
        sort(nums.begin(),nums.end());
        int last=1e9;
       
        while(j<n and i<n/2 ){
            
            if(nums[j]>=nums[i]*2){
              
                i++;
                j++;
              
                ans+=2;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};