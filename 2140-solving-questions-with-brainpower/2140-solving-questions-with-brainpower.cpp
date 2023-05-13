class Solution {
    private:
    long long int  f(int i,vector<vector<int>>&questions,vector<long long int>&dp){
        int n=questions.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        long long int x=f(i+1,questions,dp);
        long long int y=f(i+questions[i][1]+1,questions,dp)+questions[i][0];
         dp[i]=max(x,y);
        return dp[i];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
       vector<long long int >dp(n+1,-1);
        return f(0,questions,dp);
        
    }
};