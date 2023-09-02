class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       int n=s.size();
        vector<bool>dp(n,false);
        dp[0]=true;
        int reacable=0;
        for(int i=1;i<n;i++){
            if(i>=minJump){
                reacable+=dp[i-minJump];
            }
            if(i>maxJump){
                reacable-=dp[i-maxJump-1];
            }
            if(reacable>0 and s[i]=='0'){
                dp[i]=true;
            }
            else{
                dp[i]=false;
            }
        }
        return dp[n-1];
    }
};