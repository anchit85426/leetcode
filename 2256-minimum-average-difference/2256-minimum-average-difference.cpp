class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sum=0;
        for(auto it :nums){
            sum+=it;
        }
        int n=nums.size();
        int mini=INT_MAX;
        long long int  current_sum=0;
        int index=0;
        for(int i=0;i<n;i++){
            current_sum+=nums[i];
            long long int x=current_sum/(i+1);
            long long int y=0;
            
            if(i!=n-1){ y=(sum-current_sum)/(n-(i+1));
                      }
            if(abs(x-y)<mini){
                index=i;
                mini=abs(x-y);
            }
        }
        return index;
    }
    
};