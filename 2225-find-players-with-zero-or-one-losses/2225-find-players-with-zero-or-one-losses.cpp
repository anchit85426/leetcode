class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        map<int,int>mpp;
        set<int>s;
        
        for(auto it :matches){
            if(!mpp[it[0]]){
                mpp[it[0]]=0;
            }
            mpp[it[1]]++;
            
        }
          
            for(auto it :mpp){
                if(it.second==1){
                    ans[1].push_back(it.first);
                }
                if(it.second==0){
                    ans[0].push_back(it.first);
                }
            }
        
       
        return ans;
    }
};