class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
       
        long long int sum=0;
        if(n<(2*k+1)){
            return ans;
        }
        for(int i=0;i<=2*k;i++){
            sum+=nums[i];
            
        }
        int j=2*k+1;
        int f=0;
        ans[k]=(sum/(2*k+1));
        for(int i=k+1;i<n;i++){
            if(j>=n){
                return ans;
            }
            sum+=nums[j];
            sum-=nums[f];
            ans[i]=sum/(2*k+1);
            f++;
            j++;
                               
                               
                              
        }
       
       
        return ans;
    }
};