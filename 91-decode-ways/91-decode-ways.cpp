class Solution {
    int x(string s,int pos,vector<int>&dp){
        if(pos==s.size()){
            return 1;
        }
        if(s[pos]=='0') return 0;
        if(pos==s.size()-1) return 1;
        if(dp[pos]!=-1) return dp[pos];
        int one =x(s,pos+1,dp);
        int two=0;
        string b=s.substr(pos,2);
        if(stoi(b)<=26 and stoi(b)>0){
            two=x(s,pos+2,dp);
        }
        return dp[pos]=one+two;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        int ans=0;
        vector<int>dp(n+2,-1);
        ans=x(s,0,dp);
        return ans;
        
    }
};