class Solution {
    int dp[120][2][2][11];
    int mod=1e9+7;
    int solve(string &lim,int idx,int prev,bool isZero,bool tight){
        int sz=lim.size();
        if(idx==sz and isZero==0)  return 1;
        if(idx==sz and isZero) return 0;
        if(dp[idx][isZero][tight][prev+1]!=-1) return dp[idx][isZero][tight][prev+1];
        
        int limit=lim[idx]-'0';
        if(!tight){
            limit=9;
        }
        long long int res=0;
        for(int i=0;i<=limit;i++){
            bool newtight=tight&&(i==limit);
            bool newZero=isZero&&(i==0);
            if(isZero or abs(i-prev)==1){
                res+=(solve(lim,idx+1,i,newZero,newtight))%mod;
            }
        }
        return dp[idx][isZero][tight][prev+1]=res%mod;
    }
    
public:
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof dp);
        int r=solve(high,0,-1,true,true)%mod;
       
        memset(dp,-1,sizeof dp);
        int l=solve(low,0,-1,true,true)%mod;
        int ans=(r-l+mod)%mod;
        int sz=low.size();
        bool flag=1;
        for(int i=1;i<sz;i++){
            if(abs(low[i-1]-low[i])!=1){
                flag=0;
                break;
            }
        }
        if(flag==1){
            ans+=1;
            ans+=mod;
            ans%=mod;
        }
        return ans;
    }
};