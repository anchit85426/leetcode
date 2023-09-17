class Solution {
    bool solve(int n,int k,int budget,vector<vector<int>>&composition,vector<int>&stock,vector<int>&cost,int mid){
        for(int i=0;i<k;i++){
            long long int ans=0;
            for(int j=0;j<n;j++){
                long long int req=1LL*mid*composition[i][j];
                req-=stock[j];
                if(req>0){
                ans+=1LL*req*cost[j];
                }
                
            }
            if(ans<=1LL*budget){
                return true;
            }
        }
        return false;
    }
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int low=0;
        int high=1e9;
        int ans=0;
        while(low<=high)
        {
            long long int mid=(low+high)/2;
            if(solve(n,k,budget,composition,stock,cost,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};