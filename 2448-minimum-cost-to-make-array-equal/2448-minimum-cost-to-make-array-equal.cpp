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
        int l=1;
        int h=1e6;
        long long int  res=-1;
        long long int ans=1e9;
        while(h>=l){
            int mid=(h+l)/2;
            long long int y1=solve(nums,mid,cost);
            long long int y2=solve(nums,mid+1,cost);
             res=min(y1,y2);
            if(y1>y2){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            
        }
        return res;
    }
};