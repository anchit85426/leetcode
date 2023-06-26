class Solution {
    vector<vector<int>>dp;
    int mod=1e9+7;
    int solve(vector<int>&locations,int Curr,int finish,int fuel){
        if(fuel<0) return 0;
        if(Curr>=locations.size()) return 0;
        if(dp[Curr][fuel]!=-1 ) return dp[Curr][fuel];
        long long int ans=0;
        if(Curr==finish)
        {
            ans++;
        }
        for(int i=0;i<locations.size();i++){
            if(i!=Curr){
                ans=(ans+solve(locations,i,finish,fuel-abs(locations[i]-locations[Curr])))%mod;
            }
        }
        return dp[Curr][fuel]=ans;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        dp.resize(n,vector<int>(fuel+5,-1));
        return solve(locations,start,finish,fuel);
    }
};