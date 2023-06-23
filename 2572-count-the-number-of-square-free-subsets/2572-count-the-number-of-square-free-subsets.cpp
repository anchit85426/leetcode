#define ll long long 
class Solution {
    int dp[1005][1<<11];
    vector<int>primes={2,3,5,7,11,13,17,19,23,29};
    ll mod=1e9+7;
    private:
    ll solve(int ind,int mask,vector<int>&nums){
        if(ind==nums.size()) return 1;
        if(dp[ind][mask]!=-1) return dp[ind][mask];
        int temp=mask;
        int num=nums[ind];
        int flag=0;
        for(int i=0;i<primes.size();i++){
            int count=0;
            
            while(num%primes[i]==0){
                count++;
                num/=primes[i];
            }
            if(count>=2){
                flag=1;
                break;
            }
            if(count>=1 and ((mask>>i)&1)){
                flag=1;
                break;
            }
            if(count){
                temp|=(1<<i);
            }
        }
        if(flag) return dp[ind][mask]=solve(ind+1,mask,nums)%mod;
        else return dp[ind][mask]=solve(ind+1,mask,nums)%mod+solve(ind+1,temp,nums)%mod;
    }
public:
    int squareFreeSubsets(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return 1LL*(solve(0,0,nums)-1+mod)%mod;
    }
};