class Solution {
    long long int solve(vector<int>&nums,int mid,vector<int>&cost){
        int i=0;
        long long int ans=0;
        for(auto it :nums){
            long long int x=abs(it-mid);
            x*=cost[i];
            ans+=x;
            i++;
        }
        return ans;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<int>v(1e6+1,0);
        int i=0;
        int  n=nums.size();
        for(auto it :nums){
            v[it]+=cost[i];
            i++;
        }
        vector<long long >prefix(1e6+1,0),suffix(1e6+1,0);
        long long int sum=0;
        int x=1e6;
        sum+=v[0];
        
        for(int i=1;i<=x;i++){
            prefix[i]=prefix[i-1]+sum;
            
            sum+=v[i];
        }
        sum=0;
        sum=v[x];
        for(i=x-1;i>=0;i--){
            suffix[i]=suffix[i+1]+sum;
            sum+=v[i];
        }
        
        long long  ans=1e18;
        for(int i=0;i<x;i++){
            ans=min(ans,prefix[i]+suffix[i]);
            
        }
        return ans;
    }
};