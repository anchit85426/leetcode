class Solution {    
    map<pair<int,int>,bool>dp;
    bool solve(int pos,int prev, vector<int>&stones,map<int,bool>&mpp,int n){
    
        if(mpp[pos]==false  or pos>stones[n-1]) return false;
        if(pos==stones[n-1]){
            
            return true;
        }
        if(dp.find({pos,prev})!=dp.end()){
            return dp[{pos,prev}];
        }
        bool a;
        if(prev-1>=1) a=solve(pos+prev-1,prev-1,stones,mpp,n);
        if(a==true){
            return true;
        }
       a=solve(pos+prev,prev,stones,mpp,n);
        if(a==true){
            return true;
        }
        a=solve(pos+prev+1,prev+1,stones,mpp,n);
        if(a==true){
            return true;
        }
       dp[{pos,prev}]=a;
    return a;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1){
            return false;
        }
        int n=stones.size();
        map<int,bool>mpp;
        for(auto it:stones){
            mpp[it]=true;
        }
        return solve(1,1,stones,mpp,n);
    }
};