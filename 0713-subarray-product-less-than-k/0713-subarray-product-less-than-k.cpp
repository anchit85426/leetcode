#define ll long long int
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ll ans=0;
        int n=nums.size();
        int j=0;
        ll product=1;
        for(int i=0;i<n;i++){
            product*=nums[i];
            while(j<=i and product>=k){
                product/=nums[j];
                j++;
            }
            ans+=(i-j)+1;
        }
        return ans;
    }
};