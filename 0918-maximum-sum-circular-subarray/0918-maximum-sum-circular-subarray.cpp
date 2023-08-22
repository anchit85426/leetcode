class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi_sum=INT_MIN;
        int sum=0;
        int array=0;
        int mini=0;
        int mini_sum=INT_MAX;
        for(auto it:nums){
            array+=it;
            if(sum+it>0){
                sum+=it;
                maxi_sum=max(maxi_sum,sum);
            }
            else{
                sum=it;
                maxi_sum=max(maxi_sum,sum);
                sum=0;
            }
            mini+=it;
            mini_sum=min(mini_sum,mini);
            if(mini>0){
                mini=0;
            }
            
        }
        if(array==mini_sum){
            return maxi_sum;
        }
        return max(array-mini_sum,maxi_sum);
    }
};