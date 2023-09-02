class Solution {
    vector<int>dp;
    set<string >st;
    int rec(string &s,int ind){
        int n=s.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res=1+rec(s,ind+1);
        int y=1;
        for(int i=ind;i<n;i++){
            string x=s.substr(ind,y);
            if(st.find(x)!=st.end()){
                res=min(res,rec(s,ind+y));
            }
            y++;
        }
        return dp[ind]=res;
    }
public:
    int minExtraChar(string s, vector<string>& d) {
       dp.resize(s.size()+1,-1);
        for(auto it:d){
            st.insert(it);
        }
       return  rec(s,0);
       
    }
};