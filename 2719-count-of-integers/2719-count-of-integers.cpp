class Solution {
     long long int  mod=1e9+7;
     long long int dp[30][405][2];
    long long int solve(string s,int min_sum,int max_sum,int index,int currsum,int tight){
        if(index==s.size()){
            return (min_sum<=currsum and max_sum>=currsum)?1:0;
        }
        if(dp[index][currsum][tight]!=-1) return dp[index][currsum][tight];
        int end=(tight==1)?s[index]-'0':9;
        long long int  ans=0;
        for(int start=0;start<=end;start++){
            int newtight=(start==end and tight==1)?1:0;
            ans=(ans+solve(s,min_sum,max_sum,index+1,currsum+start,newtight));
            ans%=mod;
                 
        }
        return dp[index][currsum][tight]=ans;   
    }
public:
   
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        long long int upper=solve(num2,min_sum,max_sum,0,0,1)%mod;
        memset(dp,-1,sizeof(dp));
        long long int lower=solve(num1,min_sum,max_sum,0,0,1)%mod;
        long long int ans=upper-lower;
        ans%=mod;
        long long int sum=0;
        for(auto it:num1){
            sum+=it-'0';
        }
        
        if(min_sum<=sum and max_sum>=sum){
            ans++;
        }
       ans%=mod;
        return (ans+mod)%mod;
    }
};