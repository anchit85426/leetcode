class Solution {
    vector<int>dp;
    
    bool solve(int index,string s,set<string>st){
        if(index>=s.size()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        string f="";
        for(int i=index;i<s.size();i++){
            f+=s[i];
            if(st.find(f)!=st.end()){
                if(solve(i+1,s,st)){
                    return true;
                }
            }
        }
        // dp[i]=0;
        return dp[index]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        dp.resize(s.size()+1,-1);
        for(auto it :wordDict){
            st.insert(it);
        }
        return solve(0,s,st);
    }
};